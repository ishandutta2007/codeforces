#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;

ll n,w,arr[N];
void solve()
{
    cin>>n>>w;
    vi ans;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]<=w)
        {
            if(arr[i]>=(w+1)/2)
            {
                cout<<1<<endl<<i<<endl;
                return;
            }
            else
            {
                ans.push_back(i);
                sum+=arr[i];
                if(sum>=(w+1)/2)
                {
                    cout<<ans.size()<<endl;
                    for(auto i:ans)
                        cout<<i<<' ';
                    cout<<endl;
                    return;
                }
            }
        }
    }
    cout<<-1<<endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;
    cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}