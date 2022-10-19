#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,k,a[N][N],c;
void cal(int l,int r,int d,int w)
{
	for(int i=l;i<=r;i+=d)
		for(int p=i;p<=i+d-1;p++)
			if(i<=n)
				for(int j=i+d;j<=r;j++)
					if(j<=n)
						a[p][j]=w;
}
void sol(int d,int w)
{
	if(d>=n)
		return;
	c=max(c,w);
	for(int i=1;i<=n;i+=d*k)
		cal(i,i+d*k-1,d,w);
	sol(d*k,w+1);	
}
int main()
{
	scanf("%d%d",&n,&k);
	sol(1,1);
	printf("%d\n",c);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			printf("%d ",a[i][j]);
	return 0;
}