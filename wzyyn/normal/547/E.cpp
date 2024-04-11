#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=500005;
int n,Q;
int ch[N][26],fa[N];
int l[N],la,nd;
void extend(int c){
	int p=la,np=++nd;
	l[np]=l[p]+1;
	for (;p&&!ch[p][c];p=fa[p])
		ch[p][c]=np;
	if (!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if (l[q]==l[p]+1) fa[np]=q;
		else{
			int nq=++nd; l[nq]=l[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for (;p&&ch[p][c]==q;p=fa[p])
				ch[p][c]=nq;
		}
	}
	la=np;
}
struct edge{
	int to,next;
}e[N];
struct node{
	int id,x,v;
};
int head[N],tot;
int dfn[N],ed[N];
vector<int> vec[N];
vector<node> vecQ[N];
int ans[N],t[N],bak[N],len[N];
char *s[N],MEM[N*2],*MEMP=MEM;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	dfn[x]=++*dfn;
	for (int i=head[x];i;i=e[i].next)
		dfs(e[i].to);
	ed[x]=*dfn;
}
void change(int x,int v){
	for (;x<=nd;x+=x&(-x)) t[x]+=v;
}
int Ask(int x){
	int ans=0;
	for (;x;x-=x&(-x)) ans+=t[x];
	return ans;
}
int ask(int x){
	x=bak[x];
	return Ask(ed[x])-Ask(dfn[x]-1);
}
int main(){
	nd=1;
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		s[i]=MEMP;
		scanf("%s",s[i]);
		len[i]=strlen(s[i]);
		la=1; MEMP+=len[i];
		For(j,0,len[i]-1){
			extend(s[i][j]-'a');
			vec[i].PB(la);
		}
	}
	For(i,1,n){
		int x=1;
		For(j,0,len[i]-1){
			int c=s[i][j]-'a';
			for (;x&&!ch[x][c];x=fa[x]);
			x=ch[x][c];	
		}
		bak[i]=x;
	}
	For(i,2,nd) add(fa[i],i);
	dfs(1);
	For(i,1,Q){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		vecQ[l-1].PB((node){i,k,-1});
		vecQ[r].PB((node){i,k,1});
	}
	For(i,1,n){
		For(j,0,vec[i].size()-1)
			change(dfn[vec[i][j]],1);
		For(j,0,vecQ[i].size()-1)
			ans[vecQ[i][j].id]+=ask(vecQ[i][j].x)*vecQ[i][j].v;
	}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}