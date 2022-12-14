#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;

int n,k,arr[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        while(arr[i]&&k)
        {
            arr[i]--;
            arr[n]++;
            k--;
        }
    }
    for(int i=1;i<=n;i++)cout<<arr[i]<<' ';
    cout<<endl;

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        solve();
    }
	return 0;
}