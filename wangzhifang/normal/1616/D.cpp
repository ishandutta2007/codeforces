#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
typedef long long ll;
constexpr int max_n=50000;
ll a[max_n+1];
bool cmp(int x,int y){
	return a[x]>a[y];
}
int stk[max_n+2];
int prv[max_n+1];
il void test(){
	int n,k;
	scanf("%d",&n);
	a[0]=0;
	for(int i=1; i<=n; ++i){
		int x;
		scanf("%d",&x);
		a[i]=a[i-1]+x;
	}
	scanf("%d",&k);
	for(int i=1; i<=n; ++i)
		a[i]=a[i]-i*ll(k)/*,printf("%d: %lld\n",i,a[i])*/;
	int top=1;
	stk[1]=0;
	prv[1]=0;
	for(int i=1; i<n; ++i){
		ll v=a[i+1];
//		printf("%lld %lld\n",v,a[stk[top]]);
		int tp=lower_bound(stk+1,stk+top+1,i+1,cmp)-stk-1;
		if(tp){
			prv[i+1]=stk[tp]+1;
			if(prv[i+1]>i){
				if(tp>1)
					prv[i+1]=stk[tp-1]+1;
				else
					prv[i+1]=0;
			}
		}
		else
			prv[i+1]=0;
//		printf("%d: %d (%d %d)\n",i+1,prv[i+1],top,stk[top]);
		v=a[i];
		while(top&&v>=a[stk[top]])
			--top;
		stk[++top]=i;
	}
	int lst=0,cnt=n;
	for(int i=1; i<=n; ++i){
		if(prv[i]>lst)
			lst=i,--cnt;
	}
	printf("%d\n",cnt);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}