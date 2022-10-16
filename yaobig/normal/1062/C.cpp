#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll qp(ll a,int k)
{
    ll ret=1;
    while(k)
    {
        if(k&1) ret=ret*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return ret;
}
char x[maxn+5];
int sum[maxn+5];

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    scanf("%s",x+1);
    rep(i,1,n) sum[i]=x[i]=='1';
    rep(i,1,n) sum[i]+=sum[i-1];
    while(q--)
    {
        int l,r; scanf("%d%d",&l,&r);
        int N=r-l+1,d=sum[r]-sum[l-1];
        ll ans=qp(2,N)-qp(2,N-d);
        printf("%I64d\n",(ans+mod)%mod);
    }
    return 0;
}