#include <bits/stdc++.h>

using namespace std;

#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second

typedef pair<int,int> pii;

const int MAXN = 100005;

struct thang
{
    int u, ts, ld;
};

vector < pii > ke[MAXN];
pii trace[MAXN];
int d[MAXN], Q[MAXN], ts[MAXN], n0[MAXN], M, N;
vector <int> a, st;
vector < thang > q[MAXN];

void nhap()
{
    scanf("%d%d",&N,&M);
    for(int i=1; i<=M; i++)
    {
        int u, v, c;scanf("%d%d%d",&u,&v,&c);
        ke[u].push_back(mp(c,v));
        ke[v].push_back(mp(c,u));
    }
    for(int i=0; i<N; i++)
    {
        if (ke[i].size()>0) sort(ke[i].begin(),ke[i].end());
    }
}

void deb()
{
    for(int i=0; i<N; i++)
        printf("k%d %d %d %d\n",i,d[i],n0[i],ts[i]);
}

bool cmp(thang a, thang b)
{
    if (a.ts==b.ts) return (a.ld<b.ld);
    return (a.ts<b.ts);
}

thang make(int ld, int ts, int u)
{
    thang t;
    t.ld=ld; t.ts=ts; t.u=u;
    return t;
}

void tinh()
{
    memset(d,255,sizeof(d));
    for(int i=0; i<N; i++)
    {
        n0[i]=1e9;
    }
    int l=0, r=0, ht=0; Q[0]=N-1;
    d[N-1]=0; trace[N-1]=mp(0,0); n0[N-1]=0;
    while (l<=r)
    {
        int u=Q[l++];
        //printf("u%d\n",u);
        q[0].push_back(make(0,0,u)); ts[u]=0;
        for(int j=0; j<ke[u].size(); j++)
        if (ke[u][j].fs==0)
        {
            int v=ke[u][j].sc;
            if (d[v]==-1)
            {
                d[v]=d[u];
                n0[v]=n0[u]+1;
                Q[++r]=v;
                trace[v]=mp(u,0);
            }
        }
    }
    while (1)
    {
        if (q[ht].empty()) break;
        for(int i=0; i<q[ht].size(); i++)
        {
            q[ht][i].ts=ts[trace[q[ht][i].u].fs];
            q[ht][i].ld=trace[q[ht][i].u].sc;
        }
        sort(q[ht].begin(),q[ht].end(),cmp);
        ts[q[ht][0].u]=1;
        for(int i=1; i<q[ht].size(); i++)
        {
            if (q[ht][i].ts==q[ht][i-1].ts&&q[ht][i].ld==q[ht][i-1].ld)
                ts[q[ht][i].u]=ts[q[ht][i-1].u];
            else ts[q[ht][i].u]=ts[q[ht][i-1].u]+1;
        }
        for(int i=0; i<q[ht].size(); i++)
        {
            int u=q[ht][i].u;
            for(int j=0; j<ke[u].size(); j++)
            {
                int v = ke[u][j].sc;
                if (d[v]==-1)
                {
                    d[v]=d[u]+1;
                    n0[v]=n0[u];
                    q[ht+1].push_back(make(0,0,v));
                    trace[v]=mp(u,ke[u][j].fs);
                } else
                {
                    //if (v==0)
                        //printf("%d (%d %d) (%d %d)\n",u,ts[trace[v].fs],ts[u],trace[v].sc,ke[u][j].sc);
                    if (d[v]==d[u]+1&&(ts[trace[v].fs]>ts[u]||(ts[trace[v].fs]==ts[u]&&trace[v].sc>ke[u][j].fs)||
                    (ts[trace[v].fs]==ts[u]&&trace[v].sc==ke[u][j].fs&&n0[trace[v].fs]>n0[u])))
                    {
                        trace[v]=mp(u,ke[u][j].fs);
                        n0[v]=n0[u];
                    }
                }
            }
        }
        ht++;
    }
   // deb();
    trace[N-1].fs=-1;
    int v=0; st.push_back(0);
    while (1)
    {
        //cout<<v<<"  "<<trace[v].fs<<endl;
        if (trace[v].fs==-1) break;
        st.push_back(trace[v].fs); a.push_back(trace[v].sc);
        v=trace[v].fs;
    }
    bool ok=0;
    while (!a.empty())
    {
        if (a.back()>0)
        {
            printf("%d",a.back());
            ok=1;
        } else if (ok) printf("%d",a.back());
        a.pop_back();
    }
    if (!ok) printf("0");
    printf("\n%d\n",st.size());
    for(int i=0; i<st.size(); i++)
        printf("%d ",st[i]);
}

int main()
{
   // freopen("test.inp","r",stdin);
    nhap();
    tinh();
    return 0;
}