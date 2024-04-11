#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,m;
ll dp[1000010][5];
char str[1000010];
int main() {
	scanf("%s",str+1);
	n = strlen(str+1);
	dp[0][0] = 1;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		if(str[i] == 'o'){
			dp[i][2]+=dp[i-1][1];
		}
		if(str[i] == 'v' && str[i-1] == 'v'){
			dp[i][1]+=dp[i-2][0];
			dp[i][3]+=dp[i-2][2];
		}
		for(int j=0;j<=3;j++)dp[i][j]+=dp[i-1][j];
	}
	cout<<dp[n][3]<<endl;
	return 0;
}