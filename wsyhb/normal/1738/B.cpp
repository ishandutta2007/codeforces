#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int s[max_n],a[max_n];
int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=n-k+1;i<=n;++i)
			scanf("%d",s+i);
		if(k==1)
			puts("YES");
		else
		{
			for(int i=n-k+2;i<=n;++i)
				a[i]=s[i]-s[i-1];
			bool ok=true;
			for(int i=n-k+2;i<n;++i)
			{
				if(a[i]>a[i+1])
				{
					ok=false;
					break;
				}
			}
			if(ok&&s[n-k+1]<=(n-k+1ll)*a[n-k+2])
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}