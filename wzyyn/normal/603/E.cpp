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
const int N=100005;
struct edge{
	int x,y,v,id;
}e[20][N*3];
int ans[N*3],fa[N],sz[N];
int px[N],py[N],top,S;
int n,m;
bool cmp(edge a,edge b){
	return a.v<b.v;
}
int get(int x){
	return x==fa[x]?x:get(fa[x]);
}
void merge(int x,int y){
	x=get(x); y=get(y);
	if (x==y) return;
	if (sz[x]>sz[y]) swap(x,y);
	if ((sz[x]&1)&&(sz[y]&1)) S-=2;
	px[++top]=x; py[top]=y;
	fa[x]=y; sz[y]+=sz[x];
}
void pop(){
	int x=px[top],y=py[top];
	fa[x]=x; sz[y]-=sz[x]; top--;
	if ((sz[x]&1)&&(sz[y]&1)) S+=2;
}
void solve(int l,int r,int m,int lo,int hi,int d){
	if (l>r) return;
	if (lo==hi){
		For(i,l,r) ans[i]=(hi==(1<<30)?-1:hi);
		return;
	}
	int mid=(l+r)/2;
	int tmp=top,cnt;
	int posi=1,v=lo;
	for (;posi<=m&&S;++posi)
		if (e[d][posi].id<=mid){
			merge(e[d][posi].x,e[d][posi].y);
			if (!S){
				v=max(v,e[d][posi].v);
				break;
			}
		}
	if (posi>m) v=1<<30;
	ans[mid]=(v==1<<30?-1:v);
	for (;top>tmp;pop());
	cnt=0;
	For(i,1,m)
		if (e[d][i].id<mid){
			if (e[d][i].v<=v&&e[d][i].id<l)
				merge(e[d][i].x,e[d][i].y);
			else e[d+1][++cnt]=e[d][i];
		}
	solve(l,mid-1,cnt,v,hi,d+1);
	for (;top>tmp;pop());
	cnt=0;
	For(i,1,m)
		if (e[d][i].v<=v){
			if (e[d][i].id<=mid&&e[d][i].v<=lo)
				merge(e[d][i].x,e[d][i].y);
			else e[d+1][++cnt]=e[d][i];
		}
	solve(mid+1,r,cnt,lo,v,d+1);
	for (;top>tmp;pop());
}
int main(){
	scanf("%d%d",&n,&m); S=n;
	For(i,1,m) scanf("%d%d%d",&e[0][i].x,&e[0][i].y,&e[0][i].v);
	For(i,1,m) e[0][i].id=i;
	sort(e[0]+1,e[0]+m+1,cmp);
	For(i,1,n) fa[i]=i,sz[i]=1;
	solve(1,m,m,0,1<<30,0);
	For(i,1,m) printf("%d\n",ans[i]);
}