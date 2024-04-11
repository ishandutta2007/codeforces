#include<bits/stdc++.h>
using namespace std;
const int max_k=100+5;
char s[max_k];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		scanf("%d%s",&k,s+1);
		int ans=0;
		for(int i=1;i<=k;++i)
		{
			if(s[i]=='A')
			{
				int j=i;
				while(j+1<=k&&s[j+1]=='P')
					++j;
				ans=max(ans,j-i);
				i=j;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}