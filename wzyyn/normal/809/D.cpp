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
const int N=500005;
int ch[N][2],fa[N],v[N];
int tg[N],n,ans,rt,nd;
bool lson(int x){
	return ch[fa[x]][1]==x;
}
void rotate(int x){
	int y=fa[x],z=fa[y];
	int l=lson(x),r=l^1;
	if (z) ch[z][lson(y)]=x;
	fa[x]=z; fa[y]=x; fa[ch[x][r]]=y;
	ch[y][l]=ch[x][r]; ch[x][r]=y;
}
void pushdown(int x){
	int ls=ch[x][0],rs=ch[x][1];
	if (ls) tg[ls]+=tg[x],v[ls]+=tg[x];
	if (rs) tg[rs]+=tg[x],v[rs]+=tg[x];
	tg[x]=0;
}
void Down(int x){
	if (fa[x]) Down(fa[x]);
	pushdown(x);
}
void splay(int x,int y){
	Down(x); 
	for (;fa[x]!=y;rotate(x))
		if (fa[fa[x]]!=y) rotate(lson(x)^lson(fa[x])?x:fa[x]);	
	if (!y) rt=x;
}
int find(int val){
	int x=rt,ans=0;
	for (;x;){
		pushdown(x);
		if (v[x]<val)
			ans=x,x=ch[x][1];
		else x=ch[x][0];
	}
	return ans;
}
int Pre(int x){
	splay(x,0);
	for (x=ch[x][0];ch[x][1];x=ch[x][1]);
	return x;
}
int Nxt(int x){
	splay(x,0);
	for (x=ch[x][1];ch[x][0];x=ch[x][0]);
	return x;
}
void erase(int x){
	int y=Pre(x),z=Nxt(x);
	splay(y,0); splay(z,y);
	ch[z][0]=fa[x]=0;
	//printf("erase %d %d %d\n",x,y,z);
}
void insert(int val){
	//cout<<v<<endl;
	int x=rt,y=0;
	for (;x;){
		pushdown(y=x);
		x=ch[x][val>=v[x]];
	}
	x=++nd; fa[x]=y; v[x]=val;
	if (y) ch[y][val>=v[y]]=x;
	splay(x,0);
}
void solve(){
	int l,r;
	scanf("%d%d",&l,&r); 
	int x=find(l),y=find(r),z=Nxt(y);
	//cout<<"INFO "<<x<<' '<<y<<' '<<z<<endl;
	if (x!=y){
		splay(x,0);
		splay(z,x);
		int p=ch[z][0];
		++v[p]; ++tg[p];
	}
	if (z!=2) erase(z),--ans;
	insert(l); ++ans;
	//output();
}
int main(){
	scanf("%d",&n);
	insert(-(1<<30)); insert(1<<30);
	For(i,1,n) solve();
	printf("%d\n",ans);
}