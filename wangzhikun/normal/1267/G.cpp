#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n;

double C[110][110] = {0};
double dp[110][10010] = {0},x;
int c[110];

int main() {
	read(n);read(x);
	dp[0][0] = 1;
	int csum = 0;
	C[0][0] = 1;
	for(int i=1;i<=100;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)C[i][j] = C[i-1][j]+C[i-1][j-1];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
		for(int k=i;k>=0;k--){
			for(int j=0;j<=csum;j++){
				dp[k+1][j+c[i]]+=dp[k][j];
			}
		}
		csum+=c[i];
	}
	double ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=csum;j++){
			ans = ans+(dp[i][j]/C[n][i])*min(x*0.5*((double)n/(n-i)+1),(double)(csum-j)/(n-i));
		}
	}
	cout<<setprecision(15)<<fixed<<ans<<endl;
	return 0;
}