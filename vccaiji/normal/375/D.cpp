#include<bits/stdc++.h>
using namespace std;
int n,m;
const int B=300;
struct query{
	int l,r,k,i;
}q[110000];
bool cmp(query a,query b){
	if(a.l/B!=b.l/B) return a.l<b.l;
	if((a.l/B)&1) return a.r<b.r;
	return a.r>b.r;
}
int dfn[110000];
int c[110000];
int cl[110000];
int tot=0;
vector<int> e[110000];
int siz[110000];
void dfs(int i,int fa){
	dfn[i]=++tot;
	siz[i]=1;
	cl[tot]=c[i];
	for(int j=0;j<e[i].size();j++){
		if(e[i][j]!=fa){
			dfs(e[i][j],i);
			siz[i]+=siz[e[i][j]];
		} 
	}
}
int cnt[110000]={};
int cnt2[110000]={};
int ans[110000];
inline void del(int cc){
	cnt[cc]--;
	if(cnt[cc]>=0) cnt2[cnt[cc]+1]--;
}
inline void add(int cc){
	cnt[cc]++;
	if(cnt[cc]>=1) cnt2[cnt[cc]]++;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1,1);
	for(int u=1;u<=m;u++){
		q[u].i=u;
		int cc,k;
		scanf("%d%d",&cc,&k);
		q[u].l=dfn[cc];
		q[u].r=dfn[cc]+siz[cc]-1;
		q[u].k=k; 
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		if(l<q[i].l)
			for(;l<q[i].l;l++) del(cl[l]); 
		else
			for(;l>q[i].l;l--) add(cl[l-1]);
		if(r<q[i].r)
		    for(;r<q[i].r;r++) add(cl[r+1]);
		else
		    for(;r>q[i].r;r--) del(cl[r]);
		ans[q[i].i]=cnt2[q[i].k];
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}