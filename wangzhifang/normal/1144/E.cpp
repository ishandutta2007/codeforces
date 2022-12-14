#include <cstdio>
#define max_k 200000
using namespace std;
int s[max_k+2];
char tmp[max_k+2];
int main(){
	int k;
	scanf("%d\n%s",&k,tmp+1);
	for(int i=0; ++i<=k; s[i]=tmp[i]-97);
	scanf("\n%s",tmp+1),s[0]=0;
	for(int i=k+1; --i; (s[i]+=tmp[i]-97)>=26&&(++s[i-1],s[i]-=26));
//	for(int i=0; ++i<=k; printf("%d ",s[i]));
	for(int i=-1; ++i<=k; s[i]>>=1)
		s[i+1]+=(s[i]&1)*26;
	for(int i=0; ++i<=k; putchar(s[i]+97));
	return 0;
}