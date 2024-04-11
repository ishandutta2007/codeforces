#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,s,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=0,ans=0;
		while(n--)
		{
			int v;
			scanf("%d",&v);
			if(v==0)v++,ans++;
			s+=v;
		}
		if(s==0)ans++;
		printf("%d\n",ans);
	}
	return 0;
}