#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b,f[100005];
int main()
{
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	b*=5;
	int d=__gcd(a,b);
	int ans=n%d;
	a/=d,b/=d,n/=d;
	f[0]=1;
	if(n>a*b)
	{
		printf("%d\n",ans);
		return 0;
	}
	for(int i=0;i<=a*b;i++)
	{
		if(f[i])
		{
			f[i+a]=1;
			f[i+b]=1;
		}
	}
	int num=0;
	while(f[n]==0)num++,n--;
	printf("%d\n",num*d+ans);
	return 0;
}