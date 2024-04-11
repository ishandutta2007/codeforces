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
const int M=6000005;
int n,d,nd,rt,pre;
int ls[M],rs[M];
int tg[M],t[M];
priority_queue<pii> q;
void add(int &k,int l,int r,int x,int y){
	if (!k) return;// k=++nd;
	if (x<=l&&r<=y) return ++tg[k],++t[k],void(0);
	int mid=(l+r)/2;
	if (x<=mid) add(ls[k],l,mid,x,y);
	if (y>mid) add(rs[k],mid+1,r,x,y);
	t[k]=max(t[ls[k]],t[rs[k]])+tg[k];
}
void change(int &k,int l,int r,int x,int p){
	if (!k) k=++nd;
	if (l==r) return t[k]=p,void(0);
	int mid=(l+r)/2;// p-=tg[k];
	if (x<=mid) change(ls[k],l,mid,x,p);
	else change(rs[k],mid+1,r,x,p);
	t[k]=max(t[ls[k]],t[rs[k]])+tg[k];
}
int ask(int k,int l,int r,int x,int y){
	if (!k||y<l||x>r) return 0;
	if (x<=l&&r<=y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y)+tg[k];
	if (x>mid) return ask(rs[k],mid+1,r,x,y)+tg[k];
	return max(ask(ls[k],l,mid,x,mid),ask(rs[k],mid+1,r,mid+1,y))+tg[k];
}
int main(){
	scanf("%d%d",&n,&d);
	For(i,1,n){
		int l,r;
		scanf("%d%d",&l,&r);
		l=max(0,l);
		q.push(pii(-r,-l));
		q.push(pii(-l,1));
	}
	pre=-1; t[0]=-(1<<30);
	while (!q.empty()){
		int l=-q.top().se;
		int r=-q.top().fi;
		q.pop();
		if (l>=0) add(rt,0,1e9,l,r);
		else{
			if (r==pre) continue;
			int u=ask(rt,0,1e9,pre,pre);
			int v=ask(rt,0,1e9,0,r-d);
			if (l==-1||u<v){
				pre=r;
				change(rt,0,1e9,r,v);
				if (r+d<=1e9) q.push(pii(-r-d,2)); 
			}
		} 
	} 
	printf("%d\n",t[1]);
}