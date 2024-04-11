#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=1005;
const ll INF=1e18;
int n,ch[27],a[N],ans,I;
ll dp[N];
string s;
int x,sz;
int main(){
	cin>>n>>s;
	s="#"+s;
	for (int i=1;i<=26;i++)cin>>ch[i];
	for (int i=1;i<=n;i++){
		sz=n;
		for (int j=i;j<=n;j++){
			x=s[j]-'a'+1;
			sz=min(sz,ch[x]);
			if (j-i+1>sz)break;
			a[i]=j;
		}
	}
	dp[0]=1;
	for (int i=1;i<=n;i++)
	for (int j=i;j<=a[i];j++)
	dp[j]=(dp[j]+dp[i-1])%MOD;
	cout<<dp[n]<<endl;
	ans=1;
	for (int i=1;i<=n;i++)ans=max(ans,a[i]-i+1);
	cout<<ans<<endl;
	ans=0;
	I=1;
	while (I<=n){
		I=a[I]+1;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}