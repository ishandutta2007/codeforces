#include<stdio.h>
#include<stdlib.h>
int n,m,zi,zj,zk,z,x,c[9];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&x),c[x]++;
	z=0x3f3f3f3f;
	for(int i=m/n;~i;i--)
		for(int j=(m-c[3]*i)/(c[4]+c[5]);j>=i;j--)
		{
			int k=(m-c[3]*i-c[4]*j)/c[5];
			if(c[5]*k-c[4]*j>=z)
				break;
			if(c[3]*i+c[4]*j+c[5]*k==m)
			{
				int t=abs(c[3]*i-c[4]*j)+abs(c[4]*j-c[5]*k);
				if(z>t)
					z=t,zi=i,zj=j,zk=k;
			}
		}
	if(z<0x3f3f3f3f)
		printf("%d %d %d\n",zi,zj,zk);
	else
		puts("-1");
}