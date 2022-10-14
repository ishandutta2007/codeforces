#include<bits/stdc++.h>
using namespace std;
int n,r[126],cnt[126];
char s[200011],tmp;
long long ans;
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=0;i<126;i++)r[i]=1;
	for(int i=1;i<=n;i++)
	{
		tmp=s[n-i+1];
		while(s[r[tmp]]!=tmp)
		{
			if(r[s[r[tmp]]]<=r[tmp])++cnt[tmp];
			++r[tmp];
		}
		++r[tmp],ans+=cnt[tmp];
		for(int i='a';i<='z';i++)if(r[tmp]<r[i])--cnt[i];
	}
	printf("%lld",ans);
	return 0;
}