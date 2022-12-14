#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 10000
int v[max_n+1];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	puts("and 1 2");
	puts("and 1 3");
	puts("and 2 3");
	puts("or 1 2");
	puts("or 1 3");
	puts("or 2 3");
	fflush(stdout);
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	v[1]=v[2]=v[3];
	for(int i=1<<29; i; i>>=1){
		if((a&i)&&(b&i)&&(c&i)){
			v[1]|=i,v[2]|=i,v[3]|=i;
			continue;
		}
		if((a&i)){
			v[1]|=i,v[2]|=i;
			continue;
		}
		if((b&i)){
			v[1]|=i,v[3]|=i;
			continue;
		}
		if((c&i)){
			v[2]|=i,v[3]|=i;
			continue;
		}
		if(!(d&i)&&!(e&i)&&!(f&i))
			continue;
		if(!(d&i)){
			v[3]|=i;
			continue;
		}
		if(!(e&i)){
			v[2]|=i;
			continue;
		}
		if(!(f&i)){
			v[1]|=i;
			continue;
		}
		while(1);
	}
	for(int i=4; i<=n; ++i){
		printf("and 1 %d\n",i);
		printf("or 1 %d\n",i);
		fflush(stdout);
		int a,b;
		scanf("%d%d",&a,&b);
		v[i]=(b^v[1])|a;
	}
//	for(int i=1; i<=n; ++i)
//		printf("&%d\n",v[i]);
	nth_element(v+1,v+k,v+n+1);
	printf("finish %d\n",v[k]);
	fflush(stdout);
	return 0;
}