#include <cstdio>
#include <algorithm>
#define max_n 5000
using namespace std;
int dp[max_n+1][max_n+1];
int n,col[max_n+1];
template<typename T>void minify(T&x,T y){
	y<x&&(x=y);
}
int main(){
    scanf("%d",&n);
    for(int i=0; ++i<=n; col[i]==col[i-1]&&(--i,--n))
    	scanf("%d",col+i);
    for(int i=0; ++i<=n; dp[i][i]=0);
    for(int d=0; ++d<n; )
        for(int l=0,r=d; ++r,(++l)+d<=n; dp[l][r]=(col[l]==col[r]?dp[l+1][r-1]:min(dp[l+1][r],dp[l][r-1]))+1);
    printf("%d\n",dp[1][n]);
    return 0;
}