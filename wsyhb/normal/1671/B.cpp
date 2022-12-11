#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int x[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",x+i);
		bool ans=false;
		for(int d=-1;d<=1;++d)
		{
			int sta=x[1]+d;
			bool ok=true;
			for(int i=1;i<=n;++i)
			{
				int delta=sta+(i-1)-x[i];
				if(delta>1||delta<-1)
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				ans=true;
				break;
			}
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}