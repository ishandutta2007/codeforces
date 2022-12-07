#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int MX=1000005;
const int N=300005;
int t[MX*3],tg[MX*3];
int a[N],b[N],n,m,Q;
void pushdown(int k){
	if (!tg[k]) return;
	tg[k*2]+=tg[k];
	tg[k*2+1]+=tg[k];
	t[k*2]+=tg[k];
	t[k*2+1]+=tg[k];
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		t[k]+=v;
		tg[k]+=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	t[k]=max(t[k*2],t[k*2+1]);
}
void find(int k,int l,int r){
	if (l==r){
		printf("%d\n",l);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (t[k*2+1]>0) find(k*2+1,mid+1,r);
	else find(k*2,l,mid);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]),change(1,1,MX,1,a[i],1);
	For(i,1,m) scanf("%d",&b[i]),change(1,1,MX,1,b[i],-1);
	scanf("%d",&Q);
	while (Q--){
		int tp,x,v;
		scanf("%d%d%d",&tp,&x,&v);
		if (tp==1){
			change(1,1,MX,1,a[x],-1);
			change(1,1,MX,1,a[x]=v,1);
		}
		else{
			change(1,1,MX,1,b[x],1);
			change(1,1,MX,1,b[x]=v,-1);
		}
		if (t[1]<=0) puts("-1");
		else find(1,1,MX);
	}
}