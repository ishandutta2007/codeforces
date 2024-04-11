#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_m 1000000
using namespace std;
int ton[max_m+3];
int dp[max_m+3][3][3];
void maxify(int&x,int y){
	y>x&&(x=y);
}
template<typename T>T min(T x,T y,T z){
	return min(x,min(y,z));
}
template<typename T>T min(T x,T y,T z,T w){
	return min(min(w,x),min(y,z));
}
int main(){
	memset(ton,0,sizeof(ton));
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(++n; --n; ++ton[x])
		scanf("%d",&x);
	memset(dp,0,sizeof(dp));
	for(int i=0; ++i<=m; )
		for(int j=min(2,ton[i])+1; --j!=-1; )
			for(int k=min(2,ton[i+1],ton[i]-j)+1; --k!=-1; )
				for(int l=min(2,ton[i+2],ton[i+1]-k,ton[i]-j-k)+1; --l!=-1; maxify(dp[i][k][l],dp[i-1][j][k]+l+(ton[i]-j-k-l)/3));
	printf("%d\n",dp[m][0][0]);
	return 0;
}