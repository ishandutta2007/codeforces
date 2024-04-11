#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 500000
struct node{
	int x,y;
	friend bool operator<(cs node&x,cs node&y){
		if(max(x.x,x.y)==max(y.x,y.y))
			return min(x.x,x.y)<min(y.x,y.y);
		return max(x.x,x.y)<max(y.x,y.y);
	}
};
node a[max_n+1];
il void test(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1; i<=n; ++i){
//		printf("(%d,%d)\n",a[i].x,a[i].y);
		if(a[i].x>=p){
			++ans;
			p=max(p,a[i].y);
		}
	}
	printf("%d\n",ans);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}