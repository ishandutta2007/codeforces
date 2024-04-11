#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 3000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
int p[maxn+5],np[maxn+5]={1,1};
int isap[maxn+5],sum[maxn+5];
int main()
{
    int num=0;
    rep(i,2,maxn)
    {
        if(np[i]==0) p[++num]=i;
        rep(j,1,num)
        {
            ll v=1ll*i*p[j];
            if(v>=maxn) break;
            np[v]=1;
            if(i%p[j]==0) break;
        }
    }
    //rep(i,1,20) printf("%d: %d\n",i,p[i]);
    vi ps;
    rep(i,2,maxn) if(np[i]==0)
    {
        int x=i;
        while(x<=maxn) ps.pb(x),x*=i;
    }
    sort(ps.begin(),ps.end());
    for(auto u: ps) for(auto v: ps)
    {
        if(u*v>maxn) break;
        if(u%v==0 || v%u==0) continue;
        isap[u*v]=1;
    }
    rep(i,1,maxn) sum[i]=sum[i-1]+isap[i];
    int n; scanf("%d",&n);
    printf("%d\n",sum[n]);
    return 0;
}