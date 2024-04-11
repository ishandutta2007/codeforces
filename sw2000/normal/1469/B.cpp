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

int n,m,arr[N],brr[N];
int solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>brr[i];
    int ma1=0,ma2=0;
    for(int i=1;i<=n;i++)
    {
        arr[i]+=arr[i-1];
        ma1=max(ma1,arr[i]);
    }
    for(int i=1;i<=m;i++)
    {
        brr[i]+=brr[i-1];
        ma2=max(ma2,brr[i]);
    }
    return ma1+ma2;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
        cout<<solve()<<endl;
	return 0;
}