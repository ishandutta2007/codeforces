#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=300005;
int n,Q,fa[N],fav[N],nd;


namespace LCT{
	int fa[N*2],vi[N*2],v[N*2];
	int ch[N*2][2],rev[N*2];
	void pushup(int x){
		vi[x]=vi[ch[x][0]]|vi[ch[x][1]]|v[x];
	}
	void Rever(int x){
		swap(ch[x][0],ch[x][1]);
		rev[x]^=1;
	}
	void pushdown(int x){
		if (rev[x]==0) return;
		if (ch[x][0]) Rever(ch[x][0]);
		if (ch[x][1]) Rever(ch[x][1]);
		rev[x]=0;
	}
	bool isroot(int x){
		return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
	}
	void rotate(int x){
		int y=fa[x],z=fa[y];
		int l=(ch[y][1]==x),r=l^1;
		if (!isroot(y)) ch[z][ch[z][1]==y]=x;
		fa[x]=z; fa[y]=x; fa[ch[x][r]]=y;
		ch[y][l]=ch[x][r]; ch[x][r]=y;
		pushup(y); pushup(x);
	}
	void Down(int x){
		if (!isroot(x)) Down(fa[x]);
		pushdown(x);
	}
	void splay(int x){
		Down(x);
		for (;!isroot(x);rotate(x)){
			int y=fa[x],z=fa[y];
			if (!isroot(y)) rotate((ch[z][0]==y)^(ch[y][0]==x)?x:y);
		}
	}
	void Access(int x){
		for (int t=0;x;t=x,x=fa[x])
			splay(x),ch[x][1]=t,pushup(x);
	}
	void makeroot(int x){
		Access(x); splay(x); Rever(x);
	}
	void Link(int x,int y){
		makeroot(x);
		fa[x]=y;
	}
	bool Qchain(int x,int y){
		makeroot(x);
		Access(y);
		splay(y);
		return vi[y];
	}
	void Cov(int k){
		if (k>n) v[k]=1;
		if (ch[k][0]) Cov(ch[k][0]);
		if (ch[k][1]) Cov(ch[k][1]);
		pushup(k);
	}
	void Cov(int x,int y){
		makeroot(x);
		Access(y);
		splay(y);
		Cov(y);
	}
}
int get(int x){
	if (x==fa[x]) return x;
	int y=fa[x];
	fa[x]=get(fa[x]);
	fav[x]^=fav[y];
	return fa[x];
}
int main(){
	scanf("%d%d",&n,&Q);
	nd=n;
	for (int i=1;i<=n;i++)
		fa[i]=i,fav[i]=0;
	for (int i=1;i<=Q;i++){
		int x,y,v; 
		scanf("%d%d%d",&x,&y,&v);
		if (get(x)!=get(y)){
			int px=get(x),py=get(y);
			fa[px]=py; fav[px]=fav[x]^fav[y]^v;
			++nd; LCT::Link(x,nd); LCT::Link(y,nd);
			puts("YES");
		}
		else if (fav[x]^fav[y]^v){
			if (LCT::Qchain(x,y))
				puts("NO");
			else{
				LCT::Cov(x,y);
				puts("YES");
			}
		}
		else
			puts("NO");
	}
}