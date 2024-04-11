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
const int N=200005;
const int M=4000005;
char s[N];
int n,ld,la,ndd,nd,rt[N],dfn[N];
int fa[N],l[N],d[N],D[N],ch[N][26];
int Fa[N][20],id[N],val[N],at[N];
int ls[M],rs[M],lv[M],rv[M];
ll ans,S[N],sum[M];
vector<int> e[N];
int extend(int c){
	int p=la,np=++nd; l[np]=l[p]+1;
	for (;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if (!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if (l[q]==l[p]+1) fa[np]=q;
		else{
			int nq=++nd; l[nq]=l[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for (;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
	return la=np;
}
int LCA(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	int tmp=d[x]-d[y];
	Rep(i,17,0) if (tmp&(1<<i)) x=Fa[x][i];
	Rep(i,17,0)
		if (Fa[x][i]!=Fa[y][i])
			x=Fa[x][i],y=Fa[y][i];
	return x==y?x:Fa[x][0];
}
int dis(int x,int y){
	return D[x]+D[y]-2*D[LCA(x,y)];
}
void insert(int &k,int l,int r,int p,int id){
	k=++nd; lv[k]=rv[k]=id;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p,id);
	else insert(rs[k],mid+1,r,p,id);
}
void pushup(int x){
	if (!ls[x]||!rs[x]){
		int k=ls[x]+rs[x];
		sum[x]=sum[k]; lv[x]=lv[k]; rv[x]=rv[k];
	}
	else{
		sum[x]=sum[ls[x]]+sum[rs[x]];
		lv[x]=lv[ls[x]]; rv[x]=rv[rs[x]];
		sum[x]+=dis(rv[ls[x]],lv[rs[x]]);
	}
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	pushup(x);
	return x;
}
void get_dfn(int x){
	dfn[x]=++*dfn;
	For(i,0,e[x].size()-1){
		d[e[x][i]]=d[x]+1;
		get_dfn(e[x][i]);
	}
}
void get_ans(int x){
	For(i,0,e[x].size()-1){
		get_ans(e[x][i]);
		rt[x]=merge(rt[x],rt[e[x][i]]);
	}
	if (rt[x]){
		ll val=sum[rt[x]]+D[lv[rt[x]]]+D[rv[rt[x]]];
		ans+=1ll*(x==1?1:l[x]-l[fa[x]])*(val/2+1);
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	nd=la=at[n+1]=1;
	Rep(i,n,1) at[i]=extend(s[i]-'a');
	For(i,2,nd) e[fa[i]].PB(i);
	get_dfn(1);
	For(i,1,nd) Fa[i][0]=fa[i],D[i]=l[i];
	For(i,1,17) For(j,1,nd) Fa[j][i]=Fa[Fa[j][i-1]][i-1];
	memset(ch,0,sizeof(ch));
	memset(l,0,sizeof(l));
	ndd=nd; nd=id[0]=la=1;
	For(i,1,n) id[i]=extend(s[i]-'a');
	For(i,1,nd) e[i].resize(0);
	For(i,2,nd) e[fa[i]].PB(i);
	For(i,2,nd) ans+=l[i]-l[fa[i]];
	For(i,0,n-1) insert(rt[id[i]],1,ndd,dfn[at[i+2]],at[i+2]);
	get_ans(1);
	printf("%lld\n",ans+1);
}