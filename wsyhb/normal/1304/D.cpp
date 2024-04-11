#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
char S[max_n];
int ans[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,S+1);
		for(int i=1;i<=n;++i)
			ans[i]=n-i+1;
		for(int i=1;i<=n-1;++i)
		{
			if(S[i]=='>')
				continue;
			int k=i+1;
			while(k<=n-1&&S[k]=='<')
				++k;
			reverse(ans+i,ans+k+1);
			i=k;
		}
		for(int i=1;i<=n;++i)
			printf("%d%c",ans[i],i<n?' ':'\n');
		for(int i=1;i<=n;++i)
			ans[i]=i;
		for(int i=1;i<=n-1;++i)
		{
			if(S[i]=='<')
				continue;
			int k=i+1;
			while(k<=n-1&&S[k]=='>')
				++k;
			reverse(ans+i,ans+k+1);
			i=k;
		}
		for(int i=1;i<=n;++i)
			printf("%d%c",ans[i],i<n?' ':'\n');
	}
	return 0;
}