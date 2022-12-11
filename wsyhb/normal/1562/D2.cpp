#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
char s[max_n];
int sum[max_n],Hash[max_n];
vector<int> pos[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d%s",&n,&q,s+1);
		for(int i=1;i<=n;++i)
		{
			sum[i]=sum[i-1]+(i&1?-1:1)*(s[i]=='+'?1:-1);
			Hash[i]=sum[i]+sum[i-1];
		}
		sort(Hash+1,Hash+n+1);
		int R=unique(Hash+1,Hash+n+1)-Hash-1;
		for(int i=1;i<=R;++i)
			pos[i].clear();
		for(int i=1;i<=n;++i)
		{
			int k=lower_bound(Hash+1,Hash+R+1,sum[i]+sum[i-1])-Hash;
			pos[k].push_back(i);
		}
		for(int i=1;i<=q;++i)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(sum[r]-sum[l-1]==0)
				puts("0");
			else if((r-l+1)&1)
			{
				puts("1");
				int k=lower_bound(Hash+1,Hash+R+1,sum[r]+sum[l-1])-Hash;
				assert(k<=R&&Hash[k]==sum[r]+sum[l-1]);
				int p=lower_bound(pos[k].begin(),pos[k].end(),l)-pos[k].begin();
				assert(p<(int)pos[k].size()&&pos[k][p]<=r);
				printf("%d\n",pos[k][p]);
			}
			else
			{
				puts("2");
				--r;
				int k=lower_bound(Hash+1,Hash+R+1,sum[r]+sum[l-1])-Hash;
				assert(k<=R&&Hash[k]==sum[r]+sum[l-1]);
				int p=lower_bound(pos[k].begin(),pos[k].end(),l)-pos[k].begin();
				assert(p<(int)pos[k].size()&&pos[k][p]<=r);
				printf("%d %d\n",pos[k][p],r+1);
			}
		}
	}
    return 0;
}