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
const int N = 100 + 10;
const int mod = 1e9 + 7;

ll arr[N];
ll solve()
{
    int n,k;
    ll ret=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    arr[0]*=k;
    for(int i=1;i<n;i++)
    {
        ret=max(ret,arr[i]*100-arr[0]);
        arr[0]+=k*arr[i];
    }
    if(!ret)return 0;
    return (ret-1)/k+1;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        cout<<solve()<<endl;
    }
	return 0;
}