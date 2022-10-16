#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int f[maxn+5];
vi ans;
vector<pii> a;

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        a.pb(mp(x,i));
    }
    sort(a.begin(),a.end(),greater<pii>());
    ll A=0;
    rep(i,0,m*k-1) f[a[i].SE]=1,A+=a[i].FI;
    int cnt=0;
    rep(i,1,n)
    {
        cnt+=f[i];
        if(cnt>=m) ans.pb(i),cnt=0;
    }
    printf("%I64d\n",A);
    rep(i,0,k-2) printf("%d%c",ans[i]," \n"[i==k-2]);
    return 0;
}