#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
char a[max_n],b[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s%s",&n,a+1,b+1);
		bool ok=true;
		for(int i=1;i<=n;++i)
		{
			if(a[i]!=b[i])
			{
				ok=false;
				break;
			}
		}
		typedef pair<int,int> P;
		vector<P> ans;
		if(!ok)
		{
			ok=true;
			for(int i=1;i<=n;++i)
			{
				if(a[i]==b[i])
				{
					ok=false;
					break;
				}
			}
			if(!ok)
			{
				puts("NO");
				continue;
			}
			ans.push_back(P(1,1));
			ans.push_back(P(1,2));
			ans.push_back(P(2,2));
		}
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i]=='0')
				continue;
			int j=i;
			while(j+1<=n&&a[j+1]=='1')
				++j;
			ans.push_back(P(i,j));
			++cnt;
			i=j;
		}
		if(cnt&1)
		{
			ans.push_back(P(1,1));
			ans.push_back(P(1,2));
			ans.push_back(P(2,2));
		}
		puts("YES");
		printf("%d\n",int(ans.size()));
		for(auto v:ans)
			printf("%d %d\n",v.first,v.second);
	}
	return 0;
}