#include<stdio.h>
typedef unsigned u;
char B[333][333];
u N[333],C[333],s,D[333],Di;
void DFS(u n,u i)
{
	if(C[n])return;
	C[n]=i;u j;
	for(j=-1;++j<s;)if(B[n][j]=='1')DFS(j,i);
	return;
}
int F(const void*x,const void*y){return*(int*)x-*(int*)y;}
int main()
{
	u n,i=-1,j,k,l;
	for(scanf("%u",&s);++i<s;--N[i])scanf("%u",N+i);
	for(i=-1;++i<s;scanf("%s",B[i]));
	for(i=-1,l=0;++i<s;)if(!C[i])DFS(i,++l);
	for(i=0;++i;)
	{
		for(Di=j=0;j<s;++j)if(C[j]==i)D[Di++]=N[j];
		if(!Di)break;
		qsort(D,Di,sizeof(u),F);
		for(Di=j=0;j<s;++j)if(C[j]==i)N[j]=D[Di++];
	}
	for(i=-1;++i<s;printf("%u%c",++N[i],i==s-1?'\n':' '));
	return 0;
}