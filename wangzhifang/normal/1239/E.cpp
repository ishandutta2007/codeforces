#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;
constexpr int max_n=25,max_a_i=50000;
constexpr int max_m=50,max_sum_a_i=max_n*max_a_i;
bitset<max_sum_a_i+1> dp[max_m+1][max_n+1];
int a[max_m+1];
int b[max_n+1],c[max_n+1];
int main(){
	int n;
	scanf("%d",&n);
	const int m=n<<1;
	int sum=0;
	for(int i=1; i<=m; ++i)
		scanf("%d",a+i);
	sort(a+1,a+m+1);
	dp[2][0][0]=1;
	for(int i=3; i<=m; ++i){
		sum+=a[i];
		dp[i][0]=dp[i-1][0];
		for(int j=min(i-2,n-1); j; --j)
			dp[i][j]=dp[i-1][j-1]<<a[i]|dp[i-1][j];
	}
	int t=sum/2;
	for(; !dp[m][n-1][t]; --t);
	int cntb=1,cntc=1;
	b[cntb]=a[1],c[cntc]=a[2];
	for(int i=m,now=n-1; i>=3; --i)
		if(dp[i-1][now][t])
			c[++cntc]=a[i];
		else
			b[++cntb]=a[i],--now,t-=a[i];
	sort(b+1,b+n+1),sort(c+1,c+n+1);
	for(int i=1; i<n; ++i)
		printf("%d ",b[i]);
	printf("%d\n",b[n]);
	for(int i=n; i; --i)
		printf("%d ",c[i]);
	return 0;
}