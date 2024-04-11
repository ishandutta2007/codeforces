#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=1e3+5;
vector<int> a[maxn];int c[maxn];int c1[maxn];int pot[maxn];bool ok[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;for(int i=0;i<n;++i) {cin>>c[i];}for(int i=0;i<n;++i) {ok[i]=false;a[i].clear();}
        for(int i=0;i<m;++i) {int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);}
        int v=(-1);for(int i=0;i<n;++i) if(a[i].empty()) v=i; ok[v]=true;pot[v]=1;
        for(int cyc=0;cyc<=n;++cyc)
        {
            for(int i=0;i<n;++i)
            {
                if(!ok[i])
                {
                    bool ok1=true;int sum=0;
                    for(int x:a[i])
                    {
                        if(!ok[x]) ok1=false;
                        sum+=pot[x];sum%=p;
                    }
                    if(ok1)
                    {
                        ok[i]=true;
                        pot[i]=(sum%p);
                    }
                }
            }
        }
        int sum=0; for(int i=0;i<n;++i) {sum+=(pot[i]*c[i]);sum%=p;}
        for(int cyc=0;cyc<2*n+2*m;++cyc)
        {
            for(int i=0;i<n;++i) c1[i]=0;
            bool ok=false;
            for(int i=0;i<n;++i) if(c[i]) ok=true;
            if(!ok) break;
            if(!c[v]) {++sum;sum%=p;}
            for(int i=0;i<n;++i)
            {
                if(c[i])
                {
                c1[i]--;
                for(int x:a[i])
                {
                    c1[x]++;
                }
                }
            }
            for(int i=0;i<n;++i) c[i]+=c1[i];
        }
        cout<<(sum%p+p)%p<<'\n';
    }
    return 0;
}