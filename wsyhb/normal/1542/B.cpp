#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(a==1)
			puts((n-1)%b==0?"Yes":"No");
		else
		{
			long long x=1;
			bool ans=false;
			while(x<=n)
			{
				if((n-x)%b==0)
				{
					ans=true;
					break;
				}
				x*=a;
			}
			puts(ans?"Yes":"No");
		}
	}
    return 0;
}