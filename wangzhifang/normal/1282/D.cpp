#include <cstdio>
using namespace std;
#define max_n 300
char s[max_n+1];
int main(){
	int n;
	puts("b");
	fflush(stdout);
	scanf("%d",&n);
	if(!n)
		return 0;
	for(int i=1; i<=n; ++i)
		putchar(s[i]='a');
	putchar('\n');
	fflush(stdout);
	int cntb;
	scanf("%d",&cntb);
	if(!cntb)
		return 0;
	s[++n]='a';
	for(int i=1,x; i<=n; ++i){
		s[i]='b';
		printf("%s\n",s+1);
		fflush(stdout);
		scanf("%d",&x);
		if(x)
			if(x<cntb)
				cntb=x;
			else
				s[i]='a';
		else
			return 0;
	}
	return 0;
}