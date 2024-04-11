#include<bits/stdc++.h>
using namespace std;
int q;
int vis[]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		int a;
		scanf("%d",&a);
		int p=1;
		while(((1<<p)-1)<a)p++;
		if(a==((1<<p)-1))
		{
			if(!vis[p])
			{
				int ans=0;
				for(int b=1;b<a;++b)ans=max(ans,__gcd(a^b,a&b));
				vis[p]=ans;
				printf("%d\n",ans);
			}
			else printf("%d\n",vis[p]);
		}
		else printf("%d\n",(1<<p)-1);
	}
	return 0;
}