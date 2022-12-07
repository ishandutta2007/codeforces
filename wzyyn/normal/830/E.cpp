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
int n,m,T,vis[N],qq[N];
int fa[N],ans[N],q[50];
int dep[N],flg;
vector<int> e[N];
void construct1(int x,int y){
	if (flg) return;
	flg=1;
	For(i,1,n) ans[i]=(i==y);
	for (;x!=y;x=fa[x]) ans[x]=1;
	puts("YES");
	For(i,1,n) printf("%d ",ans[i]);
	puts("");
}
void construct2(int x){
	if (flg) return;
	flg=1;
	For(i,1,n) ans[i]=(vis[i]==T);
	ans[x]=2;
	puts("YES");
	For(i,1,n) printf("%d ",ans[i]);
	puts("");
}
void construct3(int x,int y){
	if (flg) return;
	flg=1;
	For(i,1,n) ans[i]=(vis[i]==T);
	for (;x!=y;ans[x]=2,x=fa[x])
		if (dep[x]<dep[y]) swap(x,y);
	ans[x]=2;
	puts("YES");
	For(i,1,n) printf("%d ",ans[i]);
	puts("");
}
void construct4(int v1,int v2,int v3,int p){
	if (flg) return;
	flg=1;
	For(i,1,n) ans[i]=0;
	ans[p]=v3;
	//cout<<p<<' '<<dep[1]<<' '<<dep[2]<<' '<<dep[3]<<' '<<v1<<' '<<v2<<' '<<v3<<endl;
	for (int x=q[1];x!=p;x=fa[x])
		if (dep[x]<=v1) ans[x]=v3-(dep[x]-1)*v3/v1;
	for (int x=q[2];x!=p;x=fa[x])
		if (dep[x]<=v2) ans[x]=v3-(dep[x]-1)*v3/v2;
	for (int x=q[3];x!=p;x=fa[x])
		if (dep[x]<=v3) ans[x]=v3-(dep[x]-1)*v3/v3;
	puts("YES");
	For(i,1,n) printf("%d ",ans[i]);
	puts("");
}
void dfs(int x){
	qq[++*qq]=x;
	vis[x]=T;
	for (auto i:e[x])
		if (i!=fa[x])
			if (vis[i]!=T){
				dep[i]=dep[x]+1;
				fa[i]=x;
				dfs(i);
			}
			else construct1(x,i);
}
int tryAtry(int x){
	++T; *qq=0; fa[x]=0; dep[x]=1; dfs(x);
	if (flg) return 1;
	For(i,1,*qq) if (e[qq[i]].size()>=4)
		return construct2(qq[i]),1;
	int las=-1;
	For(i,1,*qq) if (e[qq[i]].size()>=3)
		if (las==-1) las=qq[i];
		else return construct3(qq[i],las),1;
	if (las==-1) return 0;
	++T; *qq=*q=0; fa[las]=0; dep[las]=1; dfs(las);
	For(i,1,*qq) if (e[qq[i]].size()==1) q[++*q]=qq[i];
	//For(i,1,*q) printf("%d ",q[i]);
	//puts("Bug");
	assert(*q==3);
	For(i,1,3) For(j,i+1,3)
		if (dep[q[i]]>dep[q[j]])
			swap(q[i],q[j]);
	double tmp=1.0/dep[q[1]]+1.0/dep[q[2]]+1.0/dep[q[3]];
	if (tmp>1.0+1e-9) return 0;
	if (dep[q[1]]>=3) construct4(3,3,3,las);
	else if (dep[q[2]]>=4) construct4(2,4,4,las);
	else construct4(2,3,6,las);
	return 1;
}
void solve(){
	flg=0;
	scanf("%d%d",&n,&m);
	For(i,1,n) e[i].resize(0);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	int yyn=T;
	For(i,1,n)
		if (vis[i]<=yyn){
			tryAtry(i);
			if (flg) return;
		}
	puts("NO");
}
int main(){
	//freopen("1.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--) solve();
}