#include<stdio.h>
typedef unsigned u;
u r[200],i[100],l[100],A[200],x[100],y[100];
int main()
{
	u t=0,T,a,b;
	for(scanf("%u",&T),a=b=T,T<<=1;t<T;i[r[t++]]^=1)
	{
		scanf("%u",r+t);
		if(i[r[t]]){A[l[r[t]]]=1;a--;x[r[t]]=1;A[t]=2;b--;y[r[t]]=1;}
		l[r[t]]=t;
	}
	for(t=0;t<T;t++)
	{
		if(x[r[t]])continue;
		if(a>=b){A[t]=1;a--;x[r[t]]=1;}
		else{A[t]=2;b--;y[r[t]]=1;}
	}
	for(t=0;t<T;t++)
	{
		if(A[t])continue;
		if(a){a--;A[t]=1;x[r[t]]=1;}
		else{b--;A[t]=2;y[r[t]]=1;}
	}
	for(t=0;t<100;t++)
	{
		a+=x[t];b+=y[t];
	}
	printf("%u\n%u",a*b,A[0]);
	for(t=0;++t<T;)printf(" %u",A[t]);
	putchar('\n');
	return 0;
}