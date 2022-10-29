#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 100010;

string s[N];
int n, dp[3], m, ans=0;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>s[i];
	bool allsame = true, allsameLast;
	char beg=s[n][0], end=s[n][s[n].size()-1];
	
	for(int i=n;i;--i){
		m = s[i].size();
		allsameLast = allsame;
		rep(j,0,m-1)if(s[i][j]!=beg) allsame = false;
		
		int x = dp[0], y = dp[1], z = dp[2];
		if(allsame){
			dp[0] = dp[1] = dp[2] = y * (m+1) + m;
			continue;
		}
		
		if(allsameLast){
			int nbeg = 0, nend = 0, nmid = 0, cnt = 0;
			rep(j,0,m-1) if(s[i][j]==beg) nbeg++; else break;
			for(int j=m-1;j>=0;--j) if(s[i][j]==end) nend++; else break;
			if(i<n){
				rep(j,0,m-1)if(s[i][j]==beg)
					nmid = max(nmid, ++cnt);
				else cnt = 0;
			}else{
				cnt = 1;
				rep(j,1,m-1)if(s[i][j]==s[i][j-1])
					nmid = max(nmid, ++cnt);
				else cnt = 1;
			}
			dp[0] = x*(nbeg+1) + nbeg;
			dp[1] = y*(nmid+1) + nmid;
			dp[2] = z*(nend+1) + nend;
		}else{
			dp[0] = x; dp[2] = z; dp[1] = y;
			rep(j,0,m-1) dp[1] = max(dp[1], (end==s[i][j] ? z : 0) + 1 + (beg==s[i][j] ? x : 0));
		}
	}
	rep(i,0,2)ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}