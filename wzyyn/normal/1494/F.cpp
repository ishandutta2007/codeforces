#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=3005;
int n,m;
vector<pii> e[N];
vector<pii> E[N];
namespace solver1{
	
	int ans[N*4];
	int vis[N*4];
	int ned;
	void dfs(int x){
		for (;e[x].size();){
			pii i=e[x].back();
			e[x].pop_back();
			if (!vis[i.second]){
				vis[i.second]=1;
				dfs(i.first);
				ans[++*ans]=i.first;
			}
		}
	}
	
	void dfs2(int x){
		ned--; vis[x]=1;
		for (auto i:e[x])
			if (!vis[i.first])
				dfs2(i.first);
	}
	
	bool check(int idx=-1){
		ned=0;
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++)
			if (e[i].size()) ned++;
		if (idx!=-1)
			dfs2(idx);
		else{
			for (int i=1;i<=m;i++)
				if (e[i].size()){
					dfs2(i);
					break;
				}
		}
		if (ned) return 0;
		ned=0;
		for (int i=1;i<=n;i++)
			ned+=(e[i].size()&1);
		if (ned>2) return 0;
		if (idx!=-1&&ned==2&&e[idx].size()%2==0) return 0;
		return 1;
	}
	
	vector<int> solve(int idx=-1){
		memset(vis,0,sizeof(vis));
		vector<int> sp;
		for (int i=1;i<=n;i++)
			if (e[i].size()&1)
				sp.push_back(i);
		if (sp.size()){
			e[sp[0]].push_back(pii(sp[1],m+1));
			e[sp[1]].push_back(pii(sp[0],m+1));
			if (idx!=-1&&sp[0]!=idx) swap(sp[0],sp[1]);
		}
		
		int st;
		if (idx!=-1) st=idx;
		else{
			for (int i=1;i<=n;i++)
				if (e[i].size())
					st=i;
		}
		dfs(st);
		//ans[++*ans]=1;
		int p=1;
		
		//for (int i=1;i<=*ans;i++) printf("%d ",ans[i]);
		if (sp.size()){
			for (int i=1;i<*ans;i++){
				if (ans[i]==sp[0]&&ans[i+1]==sp[1]) p=i+1;
				if (ans[i]==sp[1]&&ans[i+1]==sp[0]) p=i+1;
			}
			int pp=(p==1?*ans:p-1);
			if (idx!=-1&&ans[pp]!=idx){
				reverse(ans+1,ans+*ans+1);
				p=(*ans)-pp+1;
			}
		}
		
		else if (idx!=-1){
			for (int i=1;i<=*ans;i++)
				if (ans[i]==idx) p=i;
		}
		
		vector<int> temp;
		for (int i=1;i<=*ans;i++){
			temp.push_back(ans[p]);
			p=p%(*ans)+1;
		}
		if (!sp.size())
			temp.push_back(*temp.begin());
		
		return temp;
	}
}

namespace solver2{
	
	bool check(int idx=-1){
		int se=0;
		for (int i=1;i<=n;i++)
			se+=e[i].size();
		se/=2;
		for (int i=1;i<=n;i++)
			if (e[i].size()==se)
				if (idx==-1||i==idx)
					return 1;
		return 0;
	}
	vector<int> solve(int idx=-1){
		int se=0,p=0;
		for (int i=1;i<=n;i++)
			se+=e[i].size();
		se/=2;
		for (int i=1;i<=n;i++)
			if (e[i].size()==se)
				p=i;
		if (idx!=-1) p=idx;
		vector<int> temp;
		temp.push_back(p);
		temp.push_back(-1);
		for (auto i:e[p]){
			temp.push_back(i.first);
			temp.push_back(p);
		}
		return temp;
	}
}

void print(vector<int> vec){
	printf("%d\n",vec.size());
	for (auto i:vec) printf("%d ",i);
	puts("");
	exit(0);
}

int flg[N*4];

void Con(int type){
	for (int i=1;i<=n;i++)
		e[i].resize(0);
	for (int i=1;i<=n;i++)
		for (auto j:E[i])
			if (flg[j.second]==type)
				e[i].push_back(j);
}
void Check(int idx){
	Con(0);
	if (!solver1::check(idx)) return;
	vector<int> ans1=solver1::solve(idx);
	Con(1);
	if (!solver2::check(idx)) return;
	vector<int> ans2=solver2::solve(idx);
	
	//printf("%d %d\n",ans1.size(),ans2.size());
	for (int i=1;i<ans2.size();i++)
		ans1.push_back(ans2[i]);
	print(ans1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].push_back(pii(y,i));
		E[y].push_back(pii(x,i));
		e[x].push_back(pii(y,i));
		e[y].push_back(pii(x,i));
	}
	
	if (solver1::check())
		print(solver1::solve());
	
	if (solver2::check())
		print(solver2::solve());
	
	
	for (int i=1;i<=n;i++){
		memset(flg,0,sizeof(flg));
		for (auto j:E[i]) flg[j.second]=(E[j.first].size()&1?1:0);
		Check(i);
		for (auto j:E[i]){
			flg[j.second]^=1;
			Check(i);
			flg[j.second]^=1;
		}
	}
	
	puts("0");
}