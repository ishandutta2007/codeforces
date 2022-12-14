#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 3000 + 10;
const ll mod = 1e9 + 7;
struct tri
{
    int a,b,c;
};
//
//O(m*n^2),O(m*n^0.5)
struct Dinic
{
    const static int N = 3000 + 100;
    const static int M = 100000 + 100;
    //
    tri e[M];
    int n, s, t, e_cnt;
    int head[N], head2[N], dep[N], Q[N];
    //1~n0~e_cnt-1
    Dinic()
    {
        memset(head, -1, sizeof(head));
        e_cnt = 0;
    }
    void add(int a, int b, int c)
    {
        e[e_cnt] = {b, c, head[a]};
        head[a] = e_cnt++;
        e[e_cnt] = {a, 0, head[b]};
        head[b] = e_cnt++;
    }
    bool bfs()
    {
        int front = 0, tail = 0;
        Q[tail++] = s;
        memset(dep + 1, 0, sizeof(*dep)*n);
        dep[s] = 1;
        while(front < tail)
        {
            int u = Q[front++];
            for(int i = head[u]; ~i; i = e[i].c)
            {
                int v = e[i].a;
                if(e[i].b && !dep[v])
                {
                    dep[v] = dep[u] + 1;
                    if(v == t)
                        return 1;
                    Q[tail++] = v;
                }
            }
        }
        return 0;
    }
    int dfs(int u, int low)
    {
        if(u == t || !low)
            return low;
        int ret = 0;

        for(int &i = head2[u]; ~i; i = e[i].c)
        {
            int v = e[i].a;
            if(dep[v] == dep[u] + 1 && e[i].b)
            {
                int flow = dfs(v, min(low, e[i].b));
                if(!flow)
                    continue;
                e[i].b -= flow;
                e[i ^ 1].b += flow;
                low -= flow;
                ret += flow;
                if(!low)
                    break;
            }
        }
        return ret;
    }
    int dinic()
    {
        int ret = 0;
        while(bfs())
        {
            for(int i = 1; i <= n; i++)
                head2[i] = head[i];
            ret += dfs(s, inf);
        }
        return ret;
    }
}d;
int n,arr[N],brr[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
    d.s=n+1;
    d.t=n+2;
    d.n=n+2;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>brr[i];
        if(brr[i]>=0)
        {
            sum+=brr[i];
            d.add(d.s,i,brr[i]);
        }
        else
        {
            d.add(i,d.t,-brr[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        set<int>s;
        for(int j=i-1;j;j--)
        {
            if(arr[i]%arr[j]==0&&s.count(arr[j])==0)
            {
                s.insert(arr[j]);
                d.add(i,j,inf);
            }
        }
    }
    cout<<sum-d.dinic();
    return 0;
}