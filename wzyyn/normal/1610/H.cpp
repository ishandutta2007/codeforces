#include<bits/stdc++.h>

using namespace std;

const int N=300005;

int n,Q,ans;
int fa[N][20];
int dep[N],dfn[N],ed[N];
int q1[N],q2[N],qx[N],qy[N];
vector<int> e[N];

void dfs(int x){
	dfn[x]=++*dfn;
	for (auto i:e[x]){
		dep[i]=dep[x]+1;
		dfs(i);
	}
	ed[x]=*dfn;
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
bool cmp(int x,int y){
	return dep[qy[x]]>dep[qy[y]];
}
int jmp(int x,int dep){
	for (int i=18;i>=0;i--)
		if (dep&(1<<i))
			x=fa[x][i];
	return x;
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	x=jmp(x,dep[x]-dep[y]);
	for (int i=18;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int t[N];
void change(int k,int v){
	for (;k<N;k+=k&(-k)) t[k]+=v;
}
int ask(int k){
	int s=0;
	for (;k;k-=k&(-k)) s+=t[k];
	return s;
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=2;i<=n;i++){
		scanf("%d",&fa[i][0]);
		e[fa[i][0]].push_back(i);
	}
	dfs(1);
	for (int i=1;i<=18;i++)
		for (int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	for (int i=1;i<=Q;i++){
		scanf("%d%d",&qx[i],&qy[i]);
		if (dep[qx[i]]<dep[qy[i]])
			swap(qx[i],qy[i]);
		if (fa[qx[i]][0]==qy[i])
			return puts("-1"),0;
		if (isfa(qy[i],qx[i]))
			q1[++*q1]=i;
		else q2[++*q2]=i;
	}
	sort(q1+1,q1+*q1+1,cmp);
	for (int i=1;i<=*q1;i++){
		int id=q1[i];
		int p=jmp(qx[id],dep[qx[id]]-dep[qy[id]]-1);
		int ok=ask(ed[p])-ask(dfn[p]-1);
		ok-=ask(ed[qx[id]])-ask(dfn[qx[id]]-1);
		//cout<<id<<' '<<p<<' '<<ok<<endl;
		if (!ok){
			++ans;
			change(dfn[p],1);
		}
	}
	for (int i=1;i<=*q2;i++){
		int id=q2[i];
		int ok=ask(n);
		ok-=ask(ed[qx[id]])-ask(dfn[qx[id]]-1);
		ok-=ask(ed[qy[id]])-ask(dfn[qy[id]]-1);
		if (!ok){
			++ans;
			break;
		}
	}
	cout<<ans<<endl;
}