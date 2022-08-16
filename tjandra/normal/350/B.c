#include<stdio.h>
typedef unsigned u;
u p[100001],pi[100001];
char q[100001];
int main()
{
	u t=0,T,m=0,mi,n,nt;char c;
	for(scanf("%u",&T);t++<T;q[t]=c&15)while((c=getchar())<'0');
	for(t=0;t++<T;p[t]=n)
	{
		scanf("%u",&n);
		if(n==0)continue;
		if(pi[n])q[n]|=2;
		else pi[n]=t;
	}
	for(t=0;t++<T;)
	{
		if(!(q[t]&1))continue;
		for(n=1,nt=t;p[nt]&&!q[p[nt]];nt=p[nt])
		{
			n++;
		}
		if(n>m){m=n;mi=nt;}
	}
	printf("%u\n%u",m,mi);
	for(nt=mi;!q[nt];nt=pi[nt])printf(" %u",pi[nt]);
	putchar('\n');
	return 0;
}