#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    int a,b; scanf("%d%d",&a,&b);
    ll mx=0,mn=1ll<<60,M=1ll*n*k;
    rep(i,0,n-1)
    {
        ll l=1ll*i*k+b-a;
        l=(l%M+M)%M;
        ll g=__gcd(l,M);
        ll s=M/g;
        chmax(mx,s);
        chmin(mn,s);
    }
    rep(i,0,n-1)
    {
        ll l=1ll*i*k-b-a;
        l=(l%M+M)%M;
        ll g=__gcd(l,M);
        ll s=M/g;
        chmax(mx,s);
        chmin(mn,s);
    }
    printf("%lld %lld\n",mn,mx);
    return 0;
}