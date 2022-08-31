#include<stdio.h>
typedef unsigned u;
u n,v[105],h[105],i,j;
int main()
{
	char c;
	scanf("%u",&n);
	for(i=0;i++<n;)for(j=0;j++<n;)
	{
		while((c=getchar())<=' ');
		if(c=='.'){v[i]=j;h[j]=i;}
	}
	for(i=0;i++<n;)if(v[i]==0)goto f1;
	for(i=0;i++<n;)printf("%u %u\n",i,v[i]);
	return 0;f1:;
	for(i=0;i++<n;)if(h[i]==0)goto f2;
	for(i=0;i++<n;)printf("%u %u\n",h[i],i);
	return 0;f2:;
	printf("-1\n");
	return 0;
}