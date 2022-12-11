#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
constexpr int max_n=70;
int a[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	int ans=n-1;
	for(int l=1; l<=n; ++l)
		for(int r=l+1; r<=n; ++r){
			int cnt=r-2;
			for(int i=r+1; i<=n; ++i)
				if((a[i]-a[r])*(r-l)!=(a[r]-a[l])*(i-r))
					++cnt;
			if(cnt<ans)
				ans=cnt;
		}
	printf("%d\n",ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}