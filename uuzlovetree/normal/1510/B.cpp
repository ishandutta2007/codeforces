#include<bits/stdc++.h>
#define MAXN 1205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d;
bool has[MAXN];
int w[MAXN][MAXN];
vector<int> u,v,p,way;
//minimum weight bipartite matching
ll km(int n,int m)
{
    for(int i=1;i<=n;i++) 
    {
        p[0]=i;
        int j0=0;
        vector<int> minv(m+1,INF);
        vector<char> used(m+1,false);
        do 
        {
            used[j0]=true;
            int i0=p[j0],delta=INF,j1;
            for(int j=1;j<=m;++j)
                if(!used[j]) 
                {
                    int cur=w[i0][j]-u[i0]-v[j];
                    if(cur<minv[j]) minv[j]=cur,way[j]=j0;
                    if(minv[j]<delta) delta=minv[j],j1=j;
                }
            for(int j=0;j<=m;++j) if(used[j]) u[p[j]]+=delta,v[j]-=delta; else minv[j]-=delta;
            j0=j1;
        }while(p[j0]!=0);
        do 
        {
            int j1=way[j0];
            p[j0]=p[j1];
            j0=j1;
        }while(j0);
    }
    ll res=0;
    for(int i=1;i<=m;i++) res+=w[p[i]][i];
    return res;
}
vector<int> save;
string str;
int suf[MAXN],pre[MAXN];
int main()
{
    scanf("%d%d",&d,&n);
    memset(has,false,sizeof(has));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int x=0;
        for(int j=0;j<d;j++) x=2*x+(str[j]-'0');
        has[x]=true;
        save.push_back(x);
        ans+=__builtin_popcount(x);
    }
    ans+=n-1;
    memset(w,0,sizeof(w));
    for(int i=0;i<(1<<d);i++)
    {
        if(has[i])
        {
            for(int j=i+1;j<(1<<d);j++)
            {
                if((i&j)!=i) continue;
                if(has[j]) w[i+1][j+1]=-__builtin_popcount(i)-1;
            }
        }
    }
    u.resize((1<<d)+1); v.resize((1<<d)+1); p.resize((1<<d)+1); way.resize((1<<d)+1);
    ans+=km((1<<d),(1<<d));
    printf("%d\n",ans);
    memset(pre,0,sizeof(pre));
    memset(suf,0,sizeof(suf));
    for(int i=1;i<=(1<<d);i++)
    {
        if(w[p[i]][i]!=0)
        {
            //(p[i]-1,i-1)
            pre[i-1]=p[i]-1;
            suf[p[i]-1]=i-1;
        }
    }
    bool reset=false;
    for(auto x:save)
    {
        if(!pre[x])
        {
            if(reset) printf("R ");
            for(int i=0;i<d;i++) if(x&(1<<i)) printf("%d ",d-1-i);
            int tmp=x;
            while(suf[tmp])
            {
                int mask=tmp^suf[tmp];
                for(int i=0;i<d;i++) if(mask&(1<<i)) printf("%d ",d-1-i);
                tmp=suf[tmp];
            }
            reset=true;
        }
    }
    return 0;
}