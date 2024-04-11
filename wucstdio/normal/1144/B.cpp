#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,num1,num2,a[2005],b[2005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		if(v&1)a[++num1]=v;
		else b[++num2]=v;
	}
	sort(a+1,a+num1+1);
	sort(b+1,b+num2+1);
	int ans=0;
	if(num1<num2)
	{
		for(int i=1;i<=num2-num1-1;i++)
		  ans+=b[i];
	}
	else
	{
		for(int i=1;i<=num1-num2-1;i++)
		  ans+=a[i];
	}
	printf("%d\n",ans);
	return 0;
}