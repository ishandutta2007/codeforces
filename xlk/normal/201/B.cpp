#include<stdio.h>
int n,m,x,y;
long long a[1020],b[1020],A[1020],B[1020],z;
long long sqr(long long x)
{
	return x*x;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&x),a[i]+=x,b[j]+=x;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			A[j]+=a[i]*sqr(i*4-j*4+2);
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			B[j]+=b[i]*sqr(i*4-j*4+2);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(A[i]+B[j]<z||i+j==0)
				z=A[x=i]+B[y=j];
	printf("%I64d\n%d %d\n",z,x,y);
	return 0;
}