#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 5010, M = 1000010, mod = 1e9 + 7;

int n, m, x, u[N], v[N], d[N];

struct Node
{
    int to,next,cap;
}edge[N];
int tol;
int head[N];
int gap[N],dis[N],pre[N],cur[N];
void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];head[u]=tol++;
    edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];head[v]=tol++;
}

int sap(int start,int end,int nodenum)
{
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memcpy(cur,head,sizeof(head));
    int u=pre[start]=start,maxflow=0,aug=-1;
    gap[0]=nodenum;
    while(dis[start]<nodenum)
    {
        loop:
        for(int &i=cur[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&dis[u]==dis[v]+1)
            {
                if(aug==-1||aug>edge[i].cap)
                    aug=edge[i].cap;
                pre[v]=u;
                u=v;
                if(v==end)
                {
                    maxflow+=aug;
                    for(u=pre[u];v!=start;v=u,u=pre[u])
                    {
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        }
        int mindis=nodenum;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&mindis>dis[v])
            {
                cur[u]=i;
                mindis=dis[v];
            }
        }
        if((--gap[dis[u]])==0)break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return maxflow;
}

int jug (double k) {
    init ();
    for (int i = 1; i <= m; i++) {
        double tmp = d[i] / k;
        if (tmp > 1e9) tmp = 1e9;
        addedge (u[i], v[i], (int)tmp);
//        cout << u[i] <<' ' << v[i] << ' ' << (int)(d[i] / k) << endl;
    }
//    cout << sap (1, n, n) << endl;
    return sap (1, n, n) >= x;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int T = 100;
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d%d", &u[i], &v[i], &d[i]);
    }
    double l = 0, r = 1000000000;
//    jug (0.499);
//    return 0;
    while (T--) {
        double mid = (l + r) / 2;
        if (jug (mid)) l = mid;
        else r = mid;
    }
    printf ("%.10f", l * x);
}