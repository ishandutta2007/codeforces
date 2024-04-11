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
int n,m,c,v[1000010],pans = 0,rans = 0;
vector< vector< vector< int > > > dp;
int main() {
	read(n);read(m);
	for(int i=0;i<n;i++){
		read(c);
		v[c]++;
	}
	dp.resize(m+1);
	for(int i=1;i<=m;i++){
		if(v[i]>=9){
		pans+=((v[i]-6)/3);
			v[i] = v[i]-((v[i]-6)/3)*3;
			
		}
	}
	for(int i=1;i<=m;i++){
		dp[i].resize(v[i]+1);
		//cout<<i<<endl;
		for(int j=0;j<dp[i].size();j++){
			dp[i][j].resize(v[i+1]+1);
		}
		for(int j=0;j<dp[i].size();j++){
			for(int k=0;k<dp[i][j].size();k++)dp[i][j][k] = -1;
		}
	}
	dp[1][v[1]][v[2]] = 0;
	for(int i=1;i<=m;i++){
		for(int a = v[i];a>=0;a--){
			for(int b=v[i+1];b>=0;b--){
				rans = max(rans,dp[i][a][b]);
				if(dp[i][a][b] == -1)continue;
				if(a>=3)dp[i][a-3][b] = max(dp[i][a-3][b],dp[i][a][b]+1);
				for(int c=0;c<=a && c<=b && c<=v[i+2];c++)
				if(i+1<=m)dp[i+1][b-c][v[i+2]-c] = max(dp[i+1][b-c][v[i+2]-c],dp[i][a][b]+c);
			}
		}
	}
	cout<<pans+rans<<endl;
	return 0;
}