#include <cstdio>
#include <cctype>
using namespace std;
char c[301][301];
int main(){
	int t,n;
	for(scanf("%d",&t); t; --t){
		int a[3]={0,0,0};
		scanf("%d",&n);
		for(int i=1; i<=n; ++i){
			for(int j=0; j<n; ++j){
				while(isspace(c[i][j]=getchar()));
				if(c[i][j]=='X')
					++a[(i+j)%3];
				else
					if(c[i][j]=='O')
						++a[(i+j+1)%3];
			}
		}
		int x=0;
		for(int i=1; i<3; ++i)
			if(a[i]<a[x])
				x=i;
		for(int i=1; i<=n; ++i){
			for(int j=0; j<n; ++j)
				if(c[i][j]=='X'&&(i+j)%3==x)
					putchar('O');
				else
					if(c[i][j]=='O'&&(i+j+1)%3==x)
						putchar('X');
					else
						putchar(c[i][j]);
			putchar('\n');
		}
	}
	return 0;
}