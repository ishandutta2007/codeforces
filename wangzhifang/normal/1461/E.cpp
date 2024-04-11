#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_x 1000000
bool vis[max_x];
il void test(){
	ll k,l,r,t,y;
	int x;
	scanf("%lld%lld%lld%lld%d%lld",&k,&l,&r,&t,&x,&y);
	r-=l,k-=l;
	if(x>y){
		if(k+y>r)
			k-=y;
		if(k-t*__int128(x-y)>=0)
			puts("Yes");
		else
			puts("No");
		return;
	}
	if(y>r){
		if(k-t*__int128(x)>=0)
			puts("Yes");
		else
			puts("No");
		return;
	}
	if(k<x&&k+y>r){
		puts("No");
		return;
	}
	for(; t>0; ){
//		printf("%lld: %lld\n",t,k);
		ll d=k/x;
		if(d>=t){
			puts("Yes");
			return;
		}
		t-=d;
		k%=x;
//		printf(" %lld\n",k);
		if(vis[k]){
			puts("Yes");
			return;
		}
		vis[k]=1;
		if(k+y>r){
			puts("No");
			return;
		}
		k+=(r-k)/y*y;
//		printf(" %lld\n",k);
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}