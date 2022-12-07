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
const int M=5000005;
int ls[M],rs[M],t[M];
int ch[N][26],fa[N];
int l[N],rt[N],la,nd,ndd;
int n,K,cnt[N],len[N];
char MEM[N],*MEMP=MEM,*s[N];
vector<int> e[N];
int merge(int x,int y,int l,int r){
	if (!x||!y) return x+y;
	if (l==r) return x;
	int mid=(l+r)/2;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	t[x]=t[ls[x]]+t[rs[x]];
	return x;
}
void insert(int &k,int l,int r,int p){
	if (!k) k=++ndd; ++t[k];
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p);
	else insert(rs[k],mid+1,r,p);
}
void extend(char c,int id){
	int p=la,np=++nd;
	l[np]=l[p]+1; insert(rt[np],1,n,id);
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
	la=np;
}
void dfs(int x){
	for (auto i:e[x])
		dfs(i),rt[x]=merge(rt[x],rt[i],1,n);
	cnt[x]=t[rt[x]];
}
int main(){
	scanf("%d%d",&n,&K);
	nd=1;
	For(i,1,n){
		s[i]=MEMP;
		scanf("%s",s[i]);
		len[i]=strlen(s[i]);
		MEMP+=len[i]; la=1;
		For(j,0,len[i]-1)
			extend(s[i][j]-'a',i);
	}
	For(i,2,nd)
		e[fa[i]].PB(i);
	dfs(1);
	cnt[1]=1<<30;
	For(i,1,n){
		int x=1;
		ll ans=0;
		For(j,0,len[i]-1){
			x=ch[x][s[i][j]-'a'];
			for (;cnt[x]<K;x=fa[x]);
			ans+=l[x];
			//cout<<l[x]<<' '<<x<<' '<<s[i][j]<<endl;
		}
		printf("%lld ",ans);
	}
}