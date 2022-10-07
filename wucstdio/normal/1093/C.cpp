#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,a[200005],b[200005];
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=(n>>1);i++)
	  scanf("%I64d",&b[i]);
	a[1]=0;
	a[n]=b[1];
	for(int i=2;i<=(n>>1);i++)
	{
		a[i]=a[i-1];
		a[n-i+1]=a[n-i+2];
		if(b[i]<b[i-1])a[n-i+1]-=b[i-1]-b[i];
		else a[i]+=b[i]-b[i-1];
	}
	for(int i=1;i<=n;i++)
	  printf("%I64d ",a[i]);
	printf("\n");
	return 0;
}