#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn (1<<20)
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int a[maxn+5];
int f[maxn+5];
int cnt[maxn+5];

ll qp(ll a,int k)
{
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

int main()
{
    rep(i,1,maxn-1) cnt[i]=cnt[i>>1]+(i&1);

    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);

    rep(i,1,n) f[a[i]]++;
    per(b,0,19) per(i,0,maxn-1)
    {
        if(i&(1<<b)) f[i^(1<<b)]+=f[i];
    }
    ll ans=0;
    rep(i,0,maxn-1) ans=(ans+(cnt[i]&1?-1:1)*qp(2,f[i]))%mod;
    ans=(ans+mod)%mod;
    printf("%I64d\n",ans);
    return 0;
}