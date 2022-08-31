#include<stdio.h>
#include<string.h>
typedef unsigned u;
char S[300003],*s,*h,c;
int main()
{
	u t;S[0]='<';S[1]='3';s=S+2;
	for(scanf("%u",&t);t--;)
	{
		scanf("%s",s);
		s+=strlen(s);
		s[0]='<';s[1]='3';s+=2;
	}
	for(h=S;h<s;)
	{
		if((c=getchar())<0)goto fin;
		if(c==*h)h++;
	}
	fin:;
	printf(h==s?"yes\n":"no\n");
	return 0;
}