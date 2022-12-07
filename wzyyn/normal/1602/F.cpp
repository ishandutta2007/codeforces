#include<bits/stdc++.h>

using namespace std;

const int N=500005;
int n,d,q[N],f[N];
pair<int,int> a[N];
vector<int> op[N];

int tg[N*4],mx[N*4];
void build(int k,int l,int r){
	tg[k]=0;
	if (l==r){
		if (l==0) mx[k]=0;
		else mx[k]=-(1<<30);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	mx[k]=max(mx[k*2],mx[k*2+1]);
}
void upd(int k,int v){
	tg[k]+=v;
	mx[k]+=v;
}
void pushdown(int k){
	if (tg[k]){
		upd(k*2,tg[k]);
		upd(k*2+1,tg[k]);
		tg[k]=0;
	}
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y)
		return upd(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	mx[k]=max(mx[k*2],mx[k*2+1]);
}
void changev(int k,int l,int r,int p,int v){
	if (l==r){
		mx[k]=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (p<=mid) changev(k*2,l,mid,p,v);
	else changev(k*2+1,mid+1,r,p,v);
	mx[k]=max(mx[k*2],mx[k*2+1]);
}
int ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return mx[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return max(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}
int main(){
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].second,&a[i].first);
		if (a[i].second<d) --i,--n;
	}
	a[++n]=make_pair(1e9+1,1e9+1);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) q[++*q]=a[i].first;
	for (int i=1;i<=n;i++)
		if (a[i].second>=a[i].first){
			int p=upper_bound(q+1,q+*q+1,a[i].second)-q;
			op[p].push_back(i);
		}
	build(1,0,n);
	for (int i=1;i<=n;i++){
		for (auto j:op[i]) change(1,0,n,0,j-1,-1);
		int p=upper_bound(q+1,q+*q+1,a[i].second)-q-1;
		f[i]=ask(1,0,n,0,p)+1;
		changev(1,0,n,i,f[i]);
		if (a[i].second>=a[i].first)
			change(1,0,n,0,i-1,1);
	}
	cout<<f[n]-1<<endl;
}