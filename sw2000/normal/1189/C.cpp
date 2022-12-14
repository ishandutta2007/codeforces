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
int arr[20][N],cnt[20][N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[0][i];
	for(int i=1;i<20;i++)
    {
        for(int j=1<<i;j<=n;j++)
        {
            int t=arr[i-1][j]+arr[i-1][j-(1<<i-1)];
            cnt[i][j]=cnt[i][j-(1<<i)];
            if(t>=10)cnt[i][j]++;
            arr[i][j]=t%10;
        }
    }
    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        int ans=0;
        for(int i=1;i<20&&(1<<i<=r-l+1);i++)
        {
            ans+=cnt[i][r]-cnt[i][l-1];
        }
        cout<<ans<<endl;
    }
	return 0;
}