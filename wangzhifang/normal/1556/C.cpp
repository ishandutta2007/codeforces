#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 1000
int stk[max_n+1],sum[max_n+1];
int main(){
	int n,top=0;
	scanf("%d",&n);
	long long ans=0;
	for(int i=1,x; i<=n; ++i){
		scanf("%d",&x);
		if((i&1)){
			++top;
			stk[top]=x,sum[top]=0;
		}
		else{
			while(x>=stk[top]){
//				printf("stk %d\n",stk[top]);
				ans+=stk[top];
				x-=stk[top];
				ans+=sum[--top];
//				printf("sum %d\n",sum[top]);
				++sum[top];
				if(!top){
					if(x>0)
						sum[0]=0,x=0;
					break;
				}
			}
			if(x)
				stk[top]-=x,sum[top]=1,ans+=x;
		}
//		printf("ans:%lld\n",ans);
//		for(int i=0; i<=top; ++i)
//			printf("(%d,%d)\n",stk[i],sum[i]);
//		puts("");
	}
	printf("%lld\n",ans);
	return 0;
}