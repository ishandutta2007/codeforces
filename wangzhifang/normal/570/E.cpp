#include <cstdio>
using namespace std;
#define max_n 500
#define max_m 500
char s[max_n][max_m+1];
int f[2][max_n+1][max_m+1];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; ++i)
		scanf("%s",s[i]);
	for(int x=0; x<n; ++x)
		for(int y=n; ~--y; )
			for(int z=m; ~--z; ){
				int&c=f[x&1][y][z]=0,w=n+m-2-x-y-z;
				if(y<=x&&z<=w&&s[y][z]==s[x][w]&&!(c=x-y+w-z<=1))
					for(int i=0; i<2; ++i)
						for(int j=0; j<2; ++j)
							c=(c+f[(x-!j)&1][y+!i][z+bool(i)])%1000000007;
			}
	printf("%d\n",f[(n&1)^1][0][0]);
	return 0;
}