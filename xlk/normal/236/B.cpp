#include<stdio.h>
int a,b,c,z;
int v[1000020];
int f[1000020];
int main()
{
	for(int i=2;i<=1000000;i++)
		if(!v[i])
			for(int j=i;j<=1000000;j+=i)
				v[j]=i;
	f[1]=1;
	for(int i=2;i<=1000000;i++)
		if(v[i]==v[i/v[i]])
			f[i]=f[i/v[i]]+(f[i/v[i]]-f[i/v[i]/v[i]]);
		else
			f[i]=f[i/v[i]]*2;
	scanf("%d %d %d",&a,&b,&c);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			for(int k=1;k<=c;k++)
				z+=f[i*j*k];
	printf("%d\n",z&(1<<30)-1);
}