#include<stdio.h>
#define fr(i,n) for(int i=0;i<n;i++)
long long x[1020],y[1020],z;char s[1020][1020];int n,m;
int main()
{
	scanf("%d %d",&n,&m);fr(i,n)scanf("%s",s[i]);
	fr(i,n)fr(j,m)if(s[i][j]=='*')x[i]++,y[j]++;
	fr(i,n)fr(j,m)if(s[i][j]=='*')z+=(x[i]-1)*(y[j]-1);
	printf("%I64d",z);
}