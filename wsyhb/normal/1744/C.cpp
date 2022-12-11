#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
char s[max_n<<1];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		char str[4];
		scanf("%d%s%s",&n,str,s+1);
		char c=str[0];
		for(int i=1;i<=n;++i)
			s[i+n]=s[i];
		int nxt=-1,ans=-1e9;
		for(int i=2*n;i>=1;--i)
		{
			if(s[i]=='g')
				nxt=i;
			if(i<=n&&s[i]==c)
			{
				assert(~nxt); 
				ans=max(ans,nxt-i);
			}
		}
		assert(ans>=0);
		printf("%d\n",ans);
	}
	return 0;
}