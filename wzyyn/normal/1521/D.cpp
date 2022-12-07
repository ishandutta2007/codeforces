#include<bits/stdc++.h>
using namespace std;

const int N=100005;
vector<int> e[N];
int f[N][3],c0[N],c1[N];
int q[N],fa[N],deg[N],n;

vector<pair<int,int> > ve;
vector<pair<int,int> > vi;

void dfs(int x,int fa){
	f[x][0]=f[x][1]=f[x][2]=0;
	for (auto i:e[x])
		if (i!=fa){
			dfs(i,x);
			c0[i]=min(f[i][0],min(f[i][1],f[i][2]))+1;
			c1[i]=min(f[i][0],f[i][1]);
			f[x][2]=min(f[x][2]+c0[i],f[x][1]+c1[i]);
			f[x][1]=min(f[x][1]+c0[i],f[x][0]+c1[i]);
			f[x][0]=f[x][0]+c0[i];
		}
}
int get(int x){
	return fa[x]==x?fa[x]:fa[x]=get(fa[x]);
}
bool cmp(int x,int y){
	return c1[x]-c0[x]<c1[y]-c0[y];
}
void dfs2(int x,int fa,int U){
	*q=0;
	for (auto i:e[x])
		if (i!=fa) q[++*q]=i;
	sort(q+1,q+*q+1,cmp);
	int p1=(*q>=1?q[1]:-1);
	int p2=(*q>=2&&U==2?q[2]:-1);
	//cout<<x<<' '<<p1<<' '<<p2<<' '<<U<<endl;
	for (auto i:e[x])
		if (i!=fa){
			if (i==p1||i==p2){
				dfs2(i,x,1);
				::fa[get(i)]=get(x);
				++deg[x]; ++deg[i];
			}
			else{
				ve.push_back(pair<int,int>(x,i));
				dfs2(i,x,2);
			}
		}
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		e[i].resize(0);
		deg[i]=0;
		fa[i]=i;
	}
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	ve.resize(0);
	vi.resize(0);
	dfs(1,0);
	dfs2(1,0,2);
	for (int i=1;i<=n;i++)
		e[i].resize(0);
	for (int i=1;i<=n;i++)
		if (deg[i]<=1)
			e[get(i)].push_back(i);
	int la=-1;
	for (int i=1;i<=n;i++)
		if (e[i].size()){
			if (la!=-1) vi.push_back(pair<int,int>(la,e[i][0]));
			la=e[i].back();
		}
	printf("%d\n",ve.size());
	for (int i=0;i<ve.size();i++){
		printf("%d %d ",ve[i].first,ve[i].second);
		printf("%d %d\n",vi[i].first,vi[i].second);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}