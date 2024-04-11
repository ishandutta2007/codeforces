#include <cstdio>
using namespace std;
#define max_n 500
#define max_m 500
char s[max_n+1][max_m+2];
int main(){
	int t;
	scanf("%d",&t);
	for(int n,m; t; --t){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; ++i)
			scanf("%s",s[i]+1);
		for(int i=1+(n%3==0); i<=n; ){
			for(int j=1; j<=m; ++j)
				s[i][j]='X';
			i+=3;
			if(i>n)
				break;
			int p=2;
			if(n==1||(s[i-1][2]!='X'&&s[i-2][2]!='X'))
				p=1;
			s[i-1][p]=s[i-2][p]='X';
		}
		for(int i=1; i<=n; ++i)
			puts(s[i]+1);
	}
	return 0;
}