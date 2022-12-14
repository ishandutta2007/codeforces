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

ll n,arr[N],pre[N],suf[N];
bool solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pre[i]=arr[i]-pre[i-1];
        if(pre[i]<0)pre[i]=linf;
    }
    suf[n+1]=0;
    for(int i=n;i;i--)
    {
        suf[i]=arr[i]-suf[i+1];
        if(suf[i]<0)suf[i]=linf;
    }
    for(int i=1;i<=n;i++)
    {
        if(pre[i]<0)break;
        else if(i==n&&pre[n]==0)return 1;
    }
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=suf[i+2]&&arr[i+1]>=pre[i-1]&&arr[i]+pre[i-1]==arr[i+1]+suf[i+2])
            return 1;
    }
    return 0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;
	cin>>_;
	while(_--)
    {
        cout<<(solve()?"YES":"NO")<<endl;;
    }
	return 0;
}