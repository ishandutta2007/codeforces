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
pii a[N];
int n,rt,Q,q[N];
int ch[N][2],fa[N];
int f[N],ftg[N];
ll  v[N],vtg[N];
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
	if (ls){
		f[ls]+=ftg[x];
		ftg[ls]+=ftg[x];
		v[ls]+=vtg[x];
		vtg[ls]+=vtg[x];
	}
	if (rs){
		f[rs]+=ftg[x];
		ftg[rs]+=ftg[x];
		v[rs]+=vtg[x];
		vtg[rs]+=vtg[x];
	}
	ftg[x]=vtg[x]=0;
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

void erase(int &x){
	if (!x) return;
	q[++*q]=x; fa[x]=0;
	pushdown(x);
	erase(ch[x][0]);
	erase(ch[x][1]);
	x=0;
}
bool cmp(int x,int y){
	if (v[x]==v[y]) return x<y;
	return v[x]<v[y];
}
void insert(int x){
	int y=rt,z=0;
	for (;y;){
		pushdown(z=y);
		y=ch[y][cmp(x,y)^1];
	}
	fa[x]=z;
	if (z) ch[z][cmp(x,z)^1]=x;
	splay(x,0);
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
int find(int v){
	int ans=0,x=rt;
	for (;x;){
		pushdown(x);
		if (::v[x]>v)
			ans=x,x=ch[x][0];
		else x=ch[x][1];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&a[i].se,&a[i].fi);
		a[i].fi*=-1;
	}
	sort(a+1,a+n+1);
	scanf("%d",&Q);
	v[Q+1]=1ll<<60; insert(Q+1);
	v[Q+2]=-1; insert(Q+2);
	For(i,1,Q){
		scanf("%d",&v[i]);
		insert(i);
	}
	//cout<<rt<<endl; 
	//For(i,1,Q+2)
	//	cout<<fa[i]<<' '<<ch[i][0]<<' '<<ch[i][1]<<endl;
	For(i,1,n){
		//cout<<a[i].se<<endl;
		int x=find(a[i].se-1);
		int y=find(2*a[i].se);
		//cout<<x<<' '<<y<<endl;
		if (x!=y){
			int z=Pre(x);
			splay(y,0);
			//cout<<x<<' '<<y<<' '<<z<<endl;
			splay(z,y);
			erase(ch[z][1]);
		}
		splay(y,0);
		//cout<<x<<' '<<y<<' '<<ch[y][1]<<endl;
		f[y]++;
		v[y]-=a[i].se;
		int p=ch[y][1];
		f[p]++; ftg[p]++;
		v[p]-=a[i].se; vtg[p]-=a[i].se;
		for (;*q;--*q){
			int x=q[*q];
			//cout<<"ERASED "<<x<<' '<<f[x]<<' '<<v[x]<<endl; 
			f[x]++; v[x]-=a[i].se;
			insert(x);
		}
	}
	erase(rt);
	For(i,1,Q) printf("%d ",f[i]);
}