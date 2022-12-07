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
int n,k,m,Q;
int fa[25],vis[25];
vector<int> e[N];
struct node{
	int pr[8],su[8];
	int S,SS,l,r;
}t[N*4];
int get(int x){
	assert(x<25);
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
node operator +(node a,node b){
	For(i,1,4*k) fa[i]=i,vis[i]=0;
	node ans;
	ans.S=a.S+b.S;
	ans.l=a.l; ans.r=b.r;
	int l1=min(2*k,a.r-a.l+1);
	int l2=min(2*k,b.r-b.l+1);
	For(i,1,min(l1,k)) fa[i]=a.pr[i];
	For(i,1,min(l1,k)) fa[l1-i+1]=a.su[k-i+1];
	For(i,1,min(l2,k)) fa[i+l1]=b.pr[i]+l1;
	For(i,1,min(l2,k)) fa[l1+l2-i+1]=b.su[k-i+1]+l1;
	For(i,1,min(l2,k)) for (auto j:e[b.l+i-1])
		if (a.l<=j&&j<=a.r){
			int x=get(i+l1),y=get(l1+j-a.r);
			if (x!=y) ans.S--,fa[x]=y;
		}
	int nd=0;
	memset(vis,0,sizeof(vis));
	For(i,1,min(l1+l2,k)){
		int x=get(i);
		if (!vis[x]) vis[x]=i;
		ans.pr[i]=vis[x];
	}
	//cout<<233<<endl;
	For(i,1,min(l1+l2,k)){
		int x=get(l1+l2-i+1);
		if (!vis[x]) vis[x]=min(l1+l2,2*k)-i+1;
		ans.su[k-i+1]=vis[x];
	}
	return ans;
}
void build(int k,int l,int r){
	if (l==r){
		t[k].pr[1]=1;
		t[k].su[::k]=1;
		t[k].S=1;
		t[k].l=t[k].r=l;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
node ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		e[y].PB(x);
	}
	build(1,1,n);
	scanf("%d",&Q);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",ask(1,1,n,l,r).S);
	}
}