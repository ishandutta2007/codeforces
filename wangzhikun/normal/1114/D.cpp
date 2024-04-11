#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n,c[5050],dp[5050][5050] = {0};
int main() {
	read(n);
	for(int i=0;i<n;i++)read(c[i]);
	memset(dp,7,sizeof(dp));
	for(int i=0;i<n;i++)dp[i][i] = 0;
	for(int i=1;i<n;i++){
		for(int l=0;l+i<n;l++){
			int r = l+i;
			if(c[r] == c[r-1]){
				dp[l][r] = min(dp[l][r],dp[l][r-1]);
			}else{
				dp[l][r] = min(dp[l][r],dp[l][r-1]+1);
			}
			if(c[l] == c[l+1]){
				dp[l][r] = min(dp[l][r],dp[l+1][r]);
			}else{
				dp[l][r] = min(dp[l][r],dp[l+1][r]+1);
			}
			if(c[l] == c[r] && r-l>=2){
				dp[l][r] = min(dp[l][r],dp[l+1][r-1]+1);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}