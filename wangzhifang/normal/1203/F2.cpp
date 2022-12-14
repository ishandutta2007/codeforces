#include <cstdio>
#include <algorithm>
using namespace std;
#define max_n 100000
int dp[2][max_n];
struct node{
	int a,b;
	inline friend bool operator <(const node&x,const node&y){
		if(x.b>=0&&y.b>=0)
			return x.a<y.a;
		if(x.b<0&&y.b<0)
			return x.a+x.b>y.a+y.b;
		return x.b>=0;
	}
};
node p[max_n];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; ++i)
		scanf("%d%d",&p[i].a,&p[i].b);
	sort(p,p+n);
	for(int i=n; --i>=0; ){
		for(int c=max_n; --c>=0; ){
			dp[i&1][c]=dp[!(i&1)][c];
			if(p[i].a<=c&&c+p[i].b>=0)
				dp[i&1][c]=max(dp[i&1][c],dp[!(i&1)][c+p[i].b]+1);
		}
	}
	printf("%d\n",dp[0][m]);
	return 0;
}