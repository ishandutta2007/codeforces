#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
int a[max_n*2+1],pos[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n*2; ++i){
		char ch;
		scanf("\n%c",&ch);
		if(ch=='+')
			a[i]=0;
		else{
			scanf("%d",a+i);
			pos[a[i]]=i;
		}
	}
	for(int i=1; i<=n; ++i){
		int now=pos[i];
		while(1){
			if(--now)
				if(a[now])
					if(a[now]<i)
						now=pos[a[now]];
					else{
						puts("NO");
						return;
					}
				else
					break;
			else{
				puts("NO");
				return;
			}
		}
		pos[i]=now;
	}
	puts("YES");
	memset(a,0,sizeof(a));
	for(int i=1; i<=n; ++i)
		a[pos[i]]=i;
	for(int i=1; i<=n*2; ++i)
		if(a[i])
			printf("%d ",a[i]);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}