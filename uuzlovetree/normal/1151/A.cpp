#include<bits/stdc++.h>
using namespace std;
int n;
const char table[4]={'A','C','T','G'};
char s[55];
int get(int l)
{
	int res=0;
	for(int i=0;i<=3;++i)
	{
		char c=s[l+i];
		int tmp=10000,cnt=0;
		while(c!=table[i])
		{
			c++;cnt++;
			if(c>'Z')c='A';
		}
		tmp=min(tmp,cnt);
		c=s[l+i];cnt=0;
		while(c!=table[i])
		{
			c--;cnt++;
			if(c<'A')c='Z';
		}
		tmp=min(tmp,cnt);
		res+=tmp;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=1000000000;
	for(int l=1;l+3<=n;++l)
	{
		ans=min(ans,get(l));
	}
	printf("%d\n",ans);
	return 0;
}