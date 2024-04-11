#include<stdio.h>
int n,z;
int lg(int n)
{
	return n>1?lg(n+1>>1)+1:0;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	printf("%d\n",z=lg(n));
	for(int i=0;i<z;i++)
	{
		int c=0;
		for(int j=0;j<n;j++)
			if(j>>i&1)
				c++;
		printf("%d ",c);
		for(int j=0;j<n;j++)
			if(j>>i&1)
				printf("%d ",j+1);
		puts("");
	}
}