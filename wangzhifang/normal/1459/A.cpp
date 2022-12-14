#include <cstdio>
#define cs const
#define il inline
using namespace std;
int r[10000];
int main(){
	int t;
	scanf("%d",&t);
	do{
		int n,c1=0,c2=0;
		scanf("%d",&n);
		for(int i=1; i<=n; ++i)
			scanf("%1d",&r[i]);
		for(int i=1,x; i<=n; ++i){
			scanf("%1d",&x);
			if(x>r[i])
				++c1;
			else
				if(x<r[i])
					++c2;
		}
		if(c2>c1)
			puts("RED");
		else
			if(c1>c2)
				puts("BLUE");
			else
				puts("EQUAL");
	}while(--t);
	return 0;
}