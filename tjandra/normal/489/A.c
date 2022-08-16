#include<stdio.h>
#include<stdlib.h>
int N[3333],P[3333],Pi[3333];
int F(const void*x,const void*y)
{return N[*(int*)x]-N[*(int*)y];}
int main()
{
	int n,i,j,k,pi,pk;
	scanf("%d",&n);
	for(i=0;i<n;scanf("%d",N+i++))P[i]=i;
	qsort(P,n,sizeof(int),F);
	for(i=0;i<n;++i)Pi[P[i]]=i;
	printf("%d\n",n);
	for(i=0;i<n;++i)
	{
		printf("%d %d\n",i,k=P[i]);
		j=N[i];N[i]=N[k];N[k]=j;
		pi=Pi[i];pk=Pi[k];
		P[Pi[i]]=k;P[Pi[k]]=i;
		Pi[k]=pi;Pi[i]=pk;
	}
	return 0;
}