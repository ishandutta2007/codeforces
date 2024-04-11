#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define r(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define pk(x) printf("%d ",x)
#define pln(x) printf("%d\n",x)
#define F(i,a,b) for(int i=a;i<=b;i++)
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define N 200001
int a[N],b[N],k,n;
int it[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=k;i++) scanf("%d",&b[i]);
	if(k==1) 
	{
		for(int i=1;i<=n;i++) 
		if(a[i])it[i]=a[i];else {it[i]=b[1];a[i]=b[1];}
//		for(int i=1;i<=n;i++) cout<<it[i]<<" ";
		sort(it+1,it+n+1);
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=it[i])
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("Yes");else puts("No");
	}
	else puts("Yes");
}