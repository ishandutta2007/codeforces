#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 200 + 10;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    ll w=0;
    cin>>n;
    vector<pii>ans;
    vi arr(n+1);
    for(int i=1;i<=n;i++)
        arr[i]=i;
    for(int i=2;i<=n;i++)
    {
        if(i-1>n-i)ans.emplace_back(i,1);
        else ans.emplace_back(i,n);
    }
    for(int i=n-2;~i;i--)
    {
        w+=(ll)(ans[i].fi-ans[i].se)*(ans[i].fi-ans[i].se);
        swap(arr[ans[i].fi],arr[ans[i].se]);
    }
    cout<<w<<endl;
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    cout<<n-1<<endl;
    for(auto i:ans)
        cout<<i.fi<<' '<<i.se<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        solve();
    }
	return 0;
}