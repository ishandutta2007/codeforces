// LUOGU_RID: 90352160
#include <cstdio>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i,puts(""))
		for(int j=1,x; j<=m; ++j){
			scanf("%d",&x);
			if(((i^j)&1))
				printf("720720 ");
			else
				printf("%d ",720720-x*x*x*x);
		}
	return 0;
}