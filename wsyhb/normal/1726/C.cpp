#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
char s[max_n<<1];
int sum[max_n<<1];
vector<int> pos[max_n<<1];
int fa[max_n<<1];
int get_fa(int x)
{
	return fa[x]!=x?fa[x]=get_fa(fa[x]):x;
}
inline void merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
		fa[x]=y; 
}
namespace ST
{
	int f[20][max_n<<1],Log[max_n<<1];
	inline void init(int len)
	{
		Log[0]=-1;
		for(int i=1;i<=len+1;++i)
			Log[i]=Log[i>>1]+1;
		for(int i=0;i<=len;++i)
			f[0][i]=sum[i];
		for(int i=1;i<=Log[len+1];++i)
			for(int j=0;j+(1<<i)-1<=len;++j)
				f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	}
	inline int query(int l,int r)
	{
		assert(l<=r);
		int k=Log[r-l+1];
		return min(f[k][l],f[k][r-(1<<k)+1]);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		pos[n].push_back(0);
		for(int i=1;i<=2*n;++i)
		{
			sum[i]=sum[i-1]+(s[i]=='('?1:-1);
			pos[sum[i]+n].push_back(i);
			fa[i]=i;
		}
		ST::init(n<<1);
		for(int i=0;i<=2*n;++i) 
			for(int l=0;l<int(pos[i].size());++l)
			{
				int r=l;
				while(r+1<int(pos[i].size())&&ST::query(pos[i][r],pos[i][r+1])+n>=i)
					++r;
				for(int j=l;j<r;++j)
					merge(pos[i][j]+1,pos[i][r]);
				for(int j=l+1;j<r;++j)
					merge(pos[i][j],pos[i][r]);
				l=r;
			}
		int ans=0;
		for(int i=1;i<=2*n;++i)
			ans+=get_fa(i)==i;
		printf("%d\n",ans);
		for(int i=0;i<=2*n;++i)
			pos[i].clear();
	}
	return 0;
}