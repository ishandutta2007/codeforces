#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
char s[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
			int j=i;
			while(j+1<=n&&s[j+1]==s[j])
				++j;
			ans=max(ans,(j-i+1ll)*(j-i+1));
			i=j;
		}
		int cnt1=0;
		for(int i=1;i<=n;++i)
			cnt1+=s[i]-'0';
		ans=max(ans,1ll*cnt1*(n-cnt1));
		printf("%lld\n",ans); 
	}
	return 0;
}