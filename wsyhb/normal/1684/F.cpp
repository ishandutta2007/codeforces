#include<bits/stdc++.h>
using namespace std;
int n,m;
const int max_n=2e5+5;
int a[max_n],Hash[max_n],rm[max_n];
vector<int> pos[max_n];
namespace ST
{
	int Log[max_n],f[18][max_n];
	inline void init()
	{
		Log[0]=-1;
		for(int i=1;i<=n;++i)
		{
			Log[i]=Log[i>>1]+1;
			f[0][i]=rm[i];
		}
		for(int i=1;i<=Log[n];++i)
			for(int j=1;j+(1<<i)-1<=n;++j)
				f[i][j]=max(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	}
	inline int query(int l,int r)
	{
		assert(l<=r);
		int k=Log[r-l+1];
		return max(f[k][l],f[k][r-(1<<k)+1]);
	}
}
bool mark[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			Hash[i]=a[i];
		}
		sort(Hash+1,Hash+n+1);
		int R=unique(Hash+1,Hash+n+1)-Hash-1;
		for(int i=1;i<=R;++i)
			pos[i].resize(1);
		for(int i=1;i<=n;++i)
		{
			a[i]=lower_bound(Hash+1,Hash+R+1,a[i])-Hash;
			pos[a[i]].push_back(i);
			rm[i]=0;
		}
		for(int i=1;i<=m;++i)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			rm[l]=max(rm[l],r);
		}
		ST::init();
		typedef pair<int,int> P;
		vector<P> I;
		for(int v=1;v<=R;++v)
		{
			int sz=pos[v].size();
			vector<int> val(sz);
			for(int l=1;l<sz;++l)
			{
				int p=ST::query(pos[v][l-1]+1,pos[v][l]);
				int r=upper_bound(pos[v].begin(),pos[v].end(),p)-pos[v].begin()-1;
				if(l<r)
				{
					++val[l+1],--val[r];
					I.push_back(P(pos[v][l],pos[v][r]));
				}
			}
			for(int i=1;i<sz;++i)
			{
				val[i]+=val[i-1];
				mark[pos[v][i]]=(val[i]>0);
			}
		}
		int l=n+1,r=0;
		for(int i=1;i<=n;++i)
		{
			if(mark[i])
			{
				l=i;
				break;
			}
		}
		for(int i=n;i>=1;--i)
		{
			if(mark[i])
			{
				r=i;
				break;
			}
		}
		if(I.empty())
		{
			printf("%d\n",max(r-l+1,0));
			continue;
		}
		for(P v:I)
		{
			l=min(l,v.second);
			r=max(r,v.first);
		}
		sort(I.begin(),I.end());
		int ans=1e9;
		for(P v:I)
		{
			ans=min(ans,r-min(l,v.first)+1);
			r=max(r,v.second);
		}
		ans=min(ans,r-l+1);
		printf("%d\n",ans);
	}
	return 0;
}