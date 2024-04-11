#include<bits/stdc++.h>
using namespace std;
const int max_m=1e5+5;
vector<int> a[max_m];
const int max_R=2e5+5;
int Hash[max_R],R;
const int max_V=3e5+5;
const int max_E=2e5+5;
int End[max_E<<1],Last[max_V],Next[max_E<<1],cur[max_V],deg[max_V],E=1;
bool mark[max_E<<1];
inline void add_edge(int x,int y)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E,++deg[x];
	End[++E]=x,Next[E]=Last[y],Last[y]=E,++deg[y];
}
void Hierholzer(int x)
{
	for(int &i=cur[x];i;i=Next[i])
	{
		if(!mark[i]&&!mark[i^1])
		{
			mark[i]=true;
			Hierholzer(End[i]);
		}
	}
}
int main()
{
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int n;
		scanf("%d",&n);
		a[i].resize(n);
		for(int j=0;j<n;++j)
		{
			scanf("%d",&a[i][j]);
			Hash[++R]=a[i][j];
		}
	}
	sort(Hash+1,Hash+R+1);
	R=unique(Hash+1,Hash+R+1)-Hash-1;
	for(int i=1;i<=m;++i)
		for(int j=int(a[i].size())-1;j>=0;--j)
		{
			int a_new=lower_bound(Hash+1,Hash+R+1,a[i][j])-Hash;
			add_edge(i,a_new+m);
		}
	for(int i=1;i<=m+R;++i)
	{
		if(deg[i]&1)
		{
			puts("NO");
			return 0;
		}
		cur[i]=Last[i];
	}
	for(int i=1;i<=m+R;++i)
		Hierholzer(i);
	puts("YES");
	for(int x=1;x<=m;++x)
	{
		string ans;
		for(int i=Last[x];i;i=Next[i])
			ans+=mark[i]?'L':'R';
		cout<<ans<<"\n";
	}
	return 0;
}