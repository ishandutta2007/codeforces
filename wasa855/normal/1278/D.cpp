#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 500005
struct Node
{
	int l,r,id;
	bool operator < (const Node &x) const
	{
		return r<x.r;
	}
};
Node a[N];
bool cmp(Node x,Node y)
{
	return x.l<y.l;
}
vector<int> G[N];
int sum;
int fa[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i].l=read(),a[i].r=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	set<Node> s;
	for(int i=1;i<=n;i++)
	{
		while(!s.empty()&&s.begin()->r<a[i].l) s.erase(s.begin());
		set<Node>::iterator j;
		for(j=s.begin();j!=s.end();++j)
		{
//			printf("%d %d\n",a[i].id,j->id);
			if(a[i].r<=j->r) break;
//			printf("%d %d\n",a[i].id,j->id);
			G[j->id].pb(a[i].id);
			G[a[i].id].pb(j->id);
			sum++;
			if(sum==n)
			{
				cout<<"NO\n";
				return 0;
			}
		}
		s.insert(a[i]);
	}
	if(sum!=n-1)
	{
		cout<<"NO\n";
		return 0;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			fa[find(i)]=find(G[i][j]);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(find(i)==i) res++;
	}
	if(res==1) cout<<"YES\n";
	else cout<<"NO\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}