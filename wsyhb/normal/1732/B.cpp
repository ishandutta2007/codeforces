#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int s[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%1d",&s[i]);
		int pos=n;
		while(pos>1&&s[pos-1]==s[pos])
			--pos;
		int ans=0,now=0;
		for(int i=1;i<=pos-1;++i)
		{
			if(s[i]^now)
			{
				++ans;
				now^=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}