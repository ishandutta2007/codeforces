#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int n,nd,ans;
int f[N],g[N],fa[N];
vector<int> e[N];
map<vector<int>,int> mp;
void dfs(int x){
	vector<int> tmp;
	tmp.resize(0);
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs(i);
			tmp.PB(f[i]);
		}
	if (x==1) return;
	sort(tmp.begin(),tmp.end());
	if (!mp[tmp]) mp[tmp]=++nd;
	f[x]=mp[tmp];
	//cout<<x<<' '<<f[x]<<endl;
}
void dfs2(int x){
	for (auto i:e[x])
		if (i!=fa[x]){
			vector<int> tmp;
			tmp.resize(0);
			for (auto j:e[x]) if (j!=i)
				tmp.PB(j==fa[x]?g[x]:f[j]);	 
			sort(tmp.begin(),tmp.end());
			if (!mp[tmp]) mp[tmp]=++nd;
			g[i]=mp[tmp];
			dfs2(i);
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	dfs2(1);
	For(i,1,n) if (e[i].size()!=4){
		vector<int> tmp;
		tmp.resize(0);
		for (auto j:e[i])
			tmp.PB(j==fa[i]?g[i]:f[j]);	 
		tmp.PB(1<<30);
		sort(tmp.begin(),tmp.end());
		if (!mp[tmp]) mp[tmp]=++nd,++ans; 
	}
	printf("%d\n",ans);
}