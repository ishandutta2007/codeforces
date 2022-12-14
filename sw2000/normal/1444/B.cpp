#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll qm(ll a,ll b)
{
    ll ret=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)ret=ret*a%mod;
    return ret;
}
ll n,arr[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    cout<<qm(2,mod-2)<<endl;
//    freopen("in.txt", "r", stdin);
    cin>>n;
    for(int i=1;i<=2*n;i++)
        cin>>arr[i];
    ll ans=1;
    sort(arr+1,arr+1+2*n);
    ll mul=0;
    for(int i=1;i<=2*n;i++)
    {
        if(i>n)ans*=i,mul+=arr[i];
        else ans*=qm(i,mod-2),mul-=arr[i];
        ans%=mod;
    }
    mul%=mod;
//    cout<<ans<<' '<<mul<<endl;
    cout<<ans*mul%mod;
    return 0;
}