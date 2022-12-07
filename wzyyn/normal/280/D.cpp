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
int n,Q,a[N];
struct node{
	int l,r,v;
	node operator +(const node &a)const{
		return (node){l,a.r,v+a.v};
	}
	bool operator <(const node &a)const{
		return v<a.v;
	}
}q[25];
struct nodee{
	node s;
	node mxl,mxr,mx;
	node mnl,mnr,mn;
	void rever(){
		swap(mxl,mnl); mxl.v*=-1; mnl.v*=-1;
		swap(mxr,mnr); mxr.v*=-1; mnr.v*=-1;
		swap(mx,mn);   mx.v*=-1;  mn.v*=-1;
		s.v*=-1;
	}
}t[N*4];
int tg[N*4];
nodee merge(nodee a,nodee b){
	nodee ans;
	ans.s=a.s+b.s;
	ans.mx=max(max(a.mx,b.mx),a.mxr+b.mxl);
	ans.mn=min(min(a.mn,b.mn),a.mnr+b.mnl);
	ans.mxl=max(a.mxl,a.s+b.mxl);
	ans.mnl=min(a.mnl,a.s+b.mnl);
	ans.mxr=max(b.mxr,a.mxr+b.s);
	ans.mnr=min(b.mnr,a.mnr+b.s);
	return ans;
}
void build(int k,int l,int r){
	if (l==r){
		t[k].s=(node){l,l,a[l]};
		t[k].mxl=t[k].mxr=t[k].mx=t[k].s;
		t[k].mnl=t[k].mnr=t[k].mn=t[k].s;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=merge(t[k*2],t[k*2+1]);
}
void rev(int k){
	t[k].rever();
	tg[k]^=1;
}
void pushdown(int k){
	if (!tg[k]) return;
	rev(k*2);
	rev(k*2+1);
	tg[k]=0;
}
void changev(int k,int l,int r,int p,int v){
	if (l==r){
		t[k].s=(node){l,l,v};
		t[k].mxl=t[k].mxr=t[k].mx=t[k].s;
		t[k].mnl=t[k].mnr=t[k].mn=t[k].s;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (p<=mid) changev(k*2,l,mid,p,v);
	else changev(k*2+1,mid+1,r,p,v);
	t[k]=merge(t[k*2],t[k*2+1]);
}
void change(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return rev(k);
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y);
	else if (x>mid) change(k*2+1,mid+1,r,x,y);
	else{
		change(k*2,l,mid,x,mid);
		change(k*2+1,mid+1,r,mid+1,y);
	}
	t[k]=merge(t[k*2],t[k*2+1]);
}
nodee ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return merge(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&Q);
	while (Q--){
		//printf("%d\n",Q);
		int tp,x,y,v;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==0) changev(1,1,n,x,y);
		else{
			scanf("%d",&v);
			int top=0,ans=0;
			for (;top<v;){
				q[++top]=ask(1,1,n,x,y).mx;
				if (q[top].v<0){
					--top; break;
				}
				ans+=q[top].v;
				change(1,1,n,q[top].l,q[top].r);
			}
			printf("%d\n",ans);
			for (;top;--top)
				change(1,1,n,q[top].l,q[top].r);
		}
	}
}