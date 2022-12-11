#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
#define INF 1073741823
#define INF2 2147483647
il void test(){
	int n;
	scanf("%d",&n);
	int l,r,ans,ans1,ans2;
	scanf("%d%d%d",&l,&r,&ans);
	ans1=ans2=ans;
	printf("%d\n",ans);
	for(int i=2; i<=n; ++i){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		if(x<l)
			l=x,ans1=INF,ans=INF2;
		if(y>r)
			r=y,ans2=INF,ans=INF2;
		if(x==l)
			c<ans1&&(ans1=c);
		if(y==r)
			c<ans2&&(ans2=c);
		if(x==l&&y==r)
			c<ans&&(ans=c);
		printf("%d\n",min(ans,ans1+ans2));
	}
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}