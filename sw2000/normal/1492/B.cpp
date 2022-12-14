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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
struct tri{int a,b,c;};
int n,arr[N];
ll solve()
{
    cin>>n;

    set<int>s;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        s.insert(i);
    }
    int lst=n;

    for(int i=n;i;i--)
    {
        if(arr[i]==*(--s.end()))
        {
            for(int j=i;j<=lst;j++)
            {
                cout<<arr[j]<<' ';
                s.erase(arr[j]);
            }
            lst=i-1;
        }
    }
    cout<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        solve();
    }
	return 0;
}