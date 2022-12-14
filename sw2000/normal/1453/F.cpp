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
const int N = 3e3 + 10;
const int mod = 1e9 + 7;
int n,arr[N],dp[N][N];
int solve() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>arr[i];
		arr[i]+=i;
	}
	for(int i=2; i<=n; i++) {
		for(int j=i; j<=n; j++)dp[i][j]=inf;
		int cnt=0;
		for(int j=i-1; j; j--)if(arr[j]>=i) {
			dp[i][arr[j]]=min(dp[i][arr[j]],dp[j][i-1]+cnt);
			cnt++;
		}
		for(int j=i+1; j<=n; j++) {
			dp[i][j]=min(dp[i][j],dp[i][j-1]);
		}
	}
	return dp[n][n];
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("in.txt","r",stdin);
	int _;
	cin>>_;
	while(_--) {
		cout<<solve()<<endl;
	}
	return 0;
}