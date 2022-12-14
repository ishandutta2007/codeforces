#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<ll, ll>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n;
pii arr[N];
ll ans;
int main()
{
//    freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&arr[i].fi,&arr[i].se);
        ans+=arr[i].se;
    }
    sort(arr+1,arr+1+n);
    ll ma=arr[1].fi+arr[1].se;

    for(int i=1;i<=n;i++)
    {
//        cout<<arr[i].fi<<' '<<arr[i].se<<endl;
        ans+=max(0ll,arr[i].fi-ma);
        ma=max(ma,arr[i].fi+arr[i].se);
    }
    cout<<ans;
	return 0;
}