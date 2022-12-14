#include <cstdio>
using namespace std;
#define max_n 65536
bool succ;
int a[max_n+1],idx[max_n];
int main(){
	int n;
	scanf("%d",&n);
	idx[0]=1;
	int i=2;
	for(; i<=n; ++i){
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		scanf("%d",a+i);
		if(idx[a[i]]){
			printf("AND %d %d\n",idx[a[i]],i);
			fflush(stdout);
			scanf("%d",a+1);
			a[1]^=a[i];
			break;
		}
		idx[a[i]]=i;
	}
	if(i>n){
		int x,y;
		printf("AND 1 %d\nAND 1 %d\n",idx[1],idx[2]);
		fflush(stdout);
		scanf("%d%d",&x,&y);
		a[1]=x|(y&1);
		for(int i=2; i<=n; ++i)
			a[i]^=a[1];
	}
	else{
		for(int j=2; j<=i; ++j)
			a[j]^=a[1];
		for(; ++i<=n; a[i]^=a[1]){
			printf("XOR 1 %d\n",i);
			fflush(stdout);
			scanf("%d",a+i);
		}
	}
	putchar('!');
	for(int i=1; i<=n; ++i)
		printf(" %d",a[i]);
	putchar('\n');
	fflush(stdout);
	return 0;
}