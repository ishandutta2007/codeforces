#include<bits/stdc++.h>
using namespace std;
const int max_n=200+5;
char s[max_n];
int cnt[26]; 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d%s",&n,&k,s+1);
		for(int i=1;i<=n;++i)
			++cnt[s[i]-'a'];
		for(int i=1;i<=k;++i)
		{
			int ans=n/k;
			for(int j=0;j<26&&j<n/k;++j)
			{
				if(cnt[j]>0)
					--cnt[j];
				else
				{
					ans=j;
					break;
				}
			}
			putchar('a'+ans);
		}
		puts("");
		for(int i=0;i<26;++i)
			cnt[i]=0;
	}
	return 0;
}