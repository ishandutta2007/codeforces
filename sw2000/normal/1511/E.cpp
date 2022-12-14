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
const int N = 3e5 + 10;
const int mod=998244353;
string boa[N];
ll two[N]{1},f[4][N],cnt,ans;
int main()
{
    srand(time(0));
	ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
	for(int i=1;i<N;i++)two[i]=two[i-1]*2%mod;
	f[0][1]=f[1][1]=1;
	for(int i=2;i<N;i++)
    {
        f[0][i]=(f[0][i-1]+f[1][i-1]*2)%mod;
        f[1][i]=f[0][i-1];
        f[2][i]=(f[2][i-1]+f[3][i-1]*2+f[1][i-1])%mod;
        f[3][i]=f[2][i-1];
    }
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>boa[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(boa[i][j]=='o')cnt++;
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0||boa[i][j-1]=='*'&&boa[i][j]=='o')
            {
                int tot=0;
                while(j+tot<m&&boa[i][j+tot]=='o')tot++;
                ans=(ans+(f[2][tot]+f[3][tot])*two[cnt-tot])%mod;
            }
            if(i==0||boa[i-1][j]=='*'&&boa[i][j]=='o')
            {
                int tot=0;
                while(i+tot<n&&boa[i+tot][j]=='o')tot++;
                ans=(ans+(f[2][tot]+f[3][tot])*two[cnt-tot])%mod;
            }
        }
    }
    cout<<ans;
	return 0;
}