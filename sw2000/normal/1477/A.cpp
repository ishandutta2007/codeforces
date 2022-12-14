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

ll n,k,arr[N];
bool solve()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=1;i<n;i++)
    {
        arr[i]-=arr[0];
    }
    k-=arr[0];
    for(int i=2;i<n;i++)
    {
        arr[1]=__gcd(arr[1],arr[i]);
    }
    return k%arr[1]==0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;
	cin>>_;
	while(_--)
    {
        cout<<(solve()?"YES":"NO")<<endl;
    }
	return 0;
}