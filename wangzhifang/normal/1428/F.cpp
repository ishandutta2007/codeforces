#include <iostream>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 500000
int a[max_n+1],f[max_n+1],g[max_n+1];
struct node{
	int v,p;
};
node stk[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%1d",a+i);
	int top=0;
	stk[0].v=n+1,stk[0].p=n+1;
	for(int i=n,now=0; i; --i){
		if(a[i]){
			++now;
			while(stk[top].v<=now)
				--top;
			f[i]=stk[top].p-i-now+1;
		}
		else{
			while(stk[top].v<=now)
				--top;
			for(; now; --now){
				stk[++top].v=now;
				stk[top].p=i+now;
			}
		}
	}
	top=0,stk[0].v=n+1,stk[0].p=0;
	for(int i=1,now=0; i<=n; ++i){
		if(a[i]){
			++now;
			while(stk[top].v<now)
				--top;
//			printf("%d: %d %d\n",i,stk[top].p,stk[top].v);
			g[i]=i-stk[top].p-now+1;
		}
		else{
			while(stk[top].v<=now)
				--top;
			for(; now; --now){
				stk[++top].v=now;
				stk[top].p=i-now;
			}
		}
	}
	long long ans=0;
	for(int i=1; i<=n; ++i)
		if(a[i]){
			int r=i;
			while(a[++r]);
			--r;
			for(int j=i; j<r; ++j)
				ans+=g[j]*ll(j-i+1);
			for(int j=r; j>i; --j)
				ans+=f[j]*ll(r-j+1);
			ans+=ll(r-i+1)*g[r]*f[i];
			if(r>i+1)
				for(int l=r-i-1,j=r-i-1; j; --j)
					ans+=j*ll(l-j+1);
			i=r+1;
		}
	printf("%lld\n",ans);
//	for(int i=1; i<=n; ++i)
//		printf("(%d %d)\n",f[i],g[i]);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}