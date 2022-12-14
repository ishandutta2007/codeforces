#include <cstdio>
using namespace std;
#define max_n 1000
int x[max_n+1],y[max_n+1];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",x+i,y+i);
	while(1){
		int s=0;
		for(int i=1; i<=n; ++i)
			if((x[i]^y[i])&1)
				++s;
		if(s&&s<n){
			printf("%d\n",s);
			for(int i=1; i<=n; ++i)
				if((x[i]^y[i])&1)
					printf("%d ",i);
			return 0;
		}
		for(int i=1; i<=n; ++i)
			s=y[i],(y[i]+=x[i])>>=1,(x[i]-=s)>>=1;
	}
}