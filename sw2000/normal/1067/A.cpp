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
const int N = 1e5 + 10;
const int mod = 998244353;

int n,arr[N];
ll f[N][2][210];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=200;i++)f[1][0][i]=1;
    for(int i=1;i<n;i++)
    {
        ll pre=0;
        for(int j=1;j<=200;j++)
        {
            if(arr[i]==-1||arr[i]==j)pre+=f[i][0][j]+f[i][1][j];
            f[i+1][0][j+1]+=pre;
            if(arr[i]==-1||arr[i]==j)f[i+1][1][j]+=f[i][0][j]+f[i][1][j];
        }
        ll suf=0;
        for(int j=200;j;j--)
        {
            if(arr[i]==-1||arr[i]==j)suf+=f[i][1][j];
            f[i+1][1][j-1]+=suf;
        }
        for(int j=1;j<=200;j++)
        {
            f[i+1][0][j]%=mod;
            f[i+1][1][j]%=mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=200;i++)if(arr[n]==-1||arr[n]==i)ans=(ans+f[n][1][i])%mod;
    cout<<ans;
	return 0;
}