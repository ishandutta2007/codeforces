#include<stdio.h>
typedef unsigned u;
u s[100000];
int main()
{
	u t=0,i,n,l,r,Ql,Qr,ans;
	for(scanf("%u%u%u%u%u%u",&n,&l,&r,&Ql,&Qr,s);++t<n;s[t]=s[t-1]+i)
	scanf("%u",&i);
	ans=s[n-1]*r+(n-1)*Qr;
	for(t=0;t++<n;)
	{
		i=s[t-1]*l+(s[n-1]-s[t-1])*r;
		if((t<<1)>n)i+=((t<<1)-n-1)*Ql;
		if(n>(t<<1))i+=(n-(t<<1)-1)*Qr;
		if(ans>i)ans=i;
	}
	printf("%u\n",ans);
	return 0;
}