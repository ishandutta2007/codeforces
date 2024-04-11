#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		s=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			s+=x;
		}
		printf("%d\n",min(m,s));
	}
	return 0;
}