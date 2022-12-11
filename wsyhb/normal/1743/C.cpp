#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
char s[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		int pos=1;
		while(pos<=n&&s[pos]!='0')
			++pos;
		int ans=0;
		for(int i=1;i<pos;++i)
			ans+=a[i];
		for(int i=pos;i<=n;++i)
		{
			assert(s[i]=='0');
			if(i==n||s[i+1]=='0')
				continue;
			int j=i+1;
			while(j+1<=n&&s[j+1]=='1')
				++j;
			int mn=1e9;
			for(int k=i;k<=j;++k)
			{
				ans+=a[k];
				mn=min(mn,a[k]);
			}
			ans-=mn;
			i=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}