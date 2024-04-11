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
const int N = 5e5 + 10;
const int mod = 1e9 + 7;

int n;
ll arr[N],two[N],cnt[N];
ll solve()
{
    for(int i=0;i<60;i++)
        cnt[i]=0;
    ll ret=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        ll t=arr[i];
        for(int j=0;j<60;j++)
        {
            cnt[j]+=t%2;
            t/=2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        ll a=0,b=0;
        ll t=arr[i];
        for(int j=0;j<60;j++)
        {
            if(t%2)
            {
                a+=cnt[j]*two[j]%mod;
                a%=mod;
                b+=n*two[j]%mod;
                b%=mod;
            }
            else
            {
                b+=cnt[j]*two[j]%mod;
                b%=mod;
            }
            t/=2;
        }
        ret+=a*b%mod;
        ret%=mod;
    }
    return ret;
}
int main()
{
    two[0]=1;
    for(int i=1;i<70;i++)
        two[i]=two[i-1]*2%mod;
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        cout<<solve()<<endl;
    }
	return 0;
}