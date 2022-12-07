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
const int N=1000005;
int n,Q,a[N];
int mn[N*4],tg[N*4],t[N*4];
void pushup(int k){
	t[k]=0;
	mn[k]=min(mn[k*2],mn[k*2+1]);
	if (mn[k*2]==mn[k]) t[k]+=t[k*2];
	if (mn[k*2+1]==mn[k]) t[k]+=t[k*2+1];
	mn[k]+=tg[k];
}
void change(int k,int l,int r,int x,int y,int v){
	//if (l==0&&r==a[0]-1) printf("C %d %d %d %d\n",x,y,v,a[0]-1);
	if (x<=l&&r<=y) return tg[k]+=v,mn[k]+=v,void(0);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	pushup(k);
}
void change(int k,int l,int r,int x,int v){
	if (l==r) return t[k]=v,void(0);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,v);
	else change(k*2+1,mid+1,r,x,v);
	pushup(k);
}
void CHG(int x,int y,int v){
	if (x>y) swap(x,y);
	change(1,0,a[0]-1,x,y-1,v);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	a[0]=N-4; a[n+1]=0;
	For(i,0,n) CHG(a[i],a[i+1],1);
	For(i,1,n) change(1,0,a[0]-1,a[i],1);
	//printf("%d %d\n",t[1],mn[1]);
	while (Q--){
		int x;
		scanf("%d",&x);
		CHG(a[x-1],a[x],-1);
		CHG(a[x],a[x+1],-1);
		change(1,0,a[0]-1,a[x],0);
		scanf("%d",&a[x]);
		CHG(a[x-1],a[x],1);
		CHG(a[x],a[x+1],1);
		change(1,0,a[0]-1,a[x],1);
		printf("%d\n",t[1]);
	}
}