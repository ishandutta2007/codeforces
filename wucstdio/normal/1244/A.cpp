#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,a,b,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&m,&a,&b,&k);
		if((n-1)/a+1+(m-1)/b+1<=k)printf("%d %d\n",(n-1)/a+1,(m-1)/b+1);
		else printf("-1\n");
	}
	return 0;
}