#include <bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
struct tri {int a, b, c;};
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
const double PI = acos(0) * 2;
int arr[N];
void solve()
{
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(!sum)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    sort(arr,arr+n);
    if(sum<0)
    {
        for(int i=0;i<n;i++)cout<<arr[i]<<' ';
    }
    else
        for(int i=n-1;i!=-1;i--)
        cout<<arr[i]<<' ';
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;
    cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}