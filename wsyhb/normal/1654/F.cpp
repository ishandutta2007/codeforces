#include<bits/stdc++.h>
using namespace std;
const int max_len=1<<18|5;
char s[max_len];
int cnt[max_len],sa[max_len],rk[max_len],sb[max_len],rk_new[max_len];
int main()
{
	int n;
	scanf("%d%s",&n,s);
	int len=1<<n;
	for(int i=0;i<len;++i)
		++cnt[s[i]-'a'];
	for(int i=1;i<26;++i)
		cnt[i]+=cnt[i-1];
	for(int i=len-1;i>=0;--i)
		sa[cnt[s[i]-'a']--]=i;
	rk[sa[1]]=1;
	int tot=1;
	for(int i=2;i<=len;++i)
		rk[sa[i]]=tot+=(s[sa[i]]!=s[sa[i-1]]);
	for(int k=0;k<=n-1&&tot<len;++k)
	{
		for(int i=1;i<=tot;++i)
			cnt[i]=0;
		for(int i=0;i<=len-1;++i)
			++cnt[rk[i]];
		for(int i=1;i<=len;++i)
			sb[i]=sa[i]^(1<<k);
		for(int i=1;i<=tot;++i)
			cnt[i]+=cnt[i-1];
		for(int i=len;i>=1;--i)
		{
			int j=sb[i];
			sa[cnt[rk[j]]--]=j;
		}
		rk_new[sa[1]]=1;
		tot=1;
		for(int i=2;i<=len;++i)
			rk_new[sa[i]]=tot+=(rk[sa[i]]!=rk[sa[i-1]]||rk[sa[i]^(1<<k)]!=rk[sa[i-1]^(1<<k)]);
		for(int i=0;i<=len-1;++i)
			rk[i]=rk_new[i];
	}
	int pos=sa[1];
	for(int i=0;i<len;++i)
		putchar(s[i^pos]);
	putchar('\n');
	return 0;
}