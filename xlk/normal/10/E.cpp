#include<stdio.h>
int n,x,y,a[420],p,z=-1;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			p=a[j],x=1;
			for(int k=i,u=a[i]-1;k<=j;k++)
				x+=u/a[k],p+=u/a[k]*a[k],u%=a[k];
			for(int k=y=0,u=p;k<n;k++)
				y+=u/a[k],u%=a[k];
			if(x<y&&(z==-1||z>p))
				z=p;
		}
	printf("%d",z);
}