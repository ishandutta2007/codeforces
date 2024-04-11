#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const int P = 1e9+7;
const int N = 2005;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,sr[N][N],sd[N][N];
int dp[N][N][2],sdp[N][N][2];
char a[N][N];

int main() {
	//freopen("test.in","r",stdin);
	scanf("%d %d\n",&n,&m);
	rep(i,1,n) scanf("%s\n",a[i]+1);
	rrep(i,n,0) rrep(j,m,0){
		sr[i][j] = sr[i][j+1] + (a[i][j]=='R');
		sd[i][j] = sd[i+1][j] + (a[i][j]=='R');
	}
	
	if(a[1][1]=='R'){
		cout<<"0\n"; return 0;
	}
	if(n+m==2){
		cout<<"1\n"; return 0;
	}
	rep(i,1,n) rep(j,1,m){
		//dp[i][j][0] : turn down; dp[i][j][1] : turn right
		if(i+j==2){
			dp[1][1][0] = dp[1][1][1] = 1;
			sdp[1][1][0] = sdp[1][1][1] = 1;
			continue;
		}
		int l, r, mid, mi, mj;
		l = 1, r = mi = i;
		while(l<=r){
			mid = l+r>>1;
			if(sd[mid+1][j]<=n-i) r = mid-1, mi=mid; else l = mid+1;
		}
		l = 1, r = mj = j;
		while(l<=r){
			mid = l+r>>1;
			if(sr[i][mid+1]<=m-j) r = mid-1, mj=mid; else l = mid+1;
		}
		//cout<<"-------"<<mi<<" "<<mj<<" "<<sd[mi-1][j]<<" "<<sr[i][mj-1]<<endl;
		dp[i][j][0] = (sdp[i][j-1][1] - sdp[i][mj-1][1] + P) % P;
		dp[i][j][1] = (sdp[i-1][j][0] - sdp[mi-1][j][0] + P) % P;
		sdp[i][j][0] = (sdp[i-1][j][0] + dp[i][j][0]) % P;
		sdp[i][j][1] = (sdp[i][j-1][1] + dp[i][j][1]) % P;
		//cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
	}
	cout<<(dp[n][m][0]+dp[n][m][1])%P<<endl;
	return 0;
}