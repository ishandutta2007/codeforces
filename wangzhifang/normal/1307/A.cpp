#include <cstdio>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n,d,ans=0;
	scanf("%d%d",&n,&d);
	for(int i=1,x; i<=n; ++i){
		scanf("%d",&x);
		if(x*(i-1)<=d)
			ans+=x,d-=x*(i-1);
		else{
			ans+=d/(i-1);
			d%=i-1;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; --t,test());
	return 0;
}