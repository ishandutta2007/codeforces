#include <cstring>
#include <cstdio>
#define max_char 255
#define max_n 1000000
using namespace std;
int ton[max_char+1],ton2[max_char+1];
char s1[max_n+2];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,sum=0;
	scanf("%s\n",s1+1);
	n=strlen(s1+1);
	for(int i=0; ++i<=n; --ton[getchar()]);
	for(int i=0; ++i<=n; ++ton[s1[i]],++ton2[s1[i]]);
	for(int i='A',p=0; ++p<=n; ){
		while(ton[i]>=0&&i<='Z')
			++i;
		--ton2[s1[p]];
//		printf("%c %d %c %d %d %d\n",i,p,s1[p],ton[i],ton[s1[p]],ton2[s1[p]]);
		if(ton[s1[p]]>0&&i<='Z')
			if(s1[p]>i||ton2[s1[p]]<ton[s1[p]])
				++ton[i],--ton[s1[p]],s1[p]=i,++sum;
	}
	printf("%d\n%s\n",sum,s1+1);
	return 0;
}