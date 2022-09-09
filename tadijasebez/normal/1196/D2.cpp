#include <bits/stdc++.h>
using namespace std;
const int N=200050;
char s[N];
int a[N];
int main()
{
	int q;
	scanf("%i",&q);
	while(q--)
	{
		int n,k;
		scanf("%i %i",&n,&k);
		scanf("%s",s+1);
		auto Solve=[&](string t)
		{
			int ans=k;
			for(int i=1;i<=n;i++)
			{
				a[i]=a[i-1]+(t[i%3]!=s[i]);
				if(i>=k) ans=min(ans,a[i]-a[i-k]);
			}
			return ans;
		};
		int ans=min({Solve("RGB"),Solve("GBR"),Solve("BRG")});
		printf("%i\n",ans);
	}
	return 0;
}