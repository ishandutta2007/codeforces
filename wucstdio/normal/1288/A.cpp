#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int t,n,d;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		int x=(int)sqrt(d);
		bool f=0;
		for(int i=max(1,x-1);i<=x+2;i++)
		  if(i+(d-1)/i<=n)f=1;
		if(f)puts("YES");
		else puts("NO");
	}
	return 0;
}