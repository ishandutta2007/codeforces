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
const int N=120005;
int n,Q,a[N],q1[N],q2[N];
int mn[N*4],tg[N*4];
int mns[N*4],atg[N*4];
int h1,t1,h2,t2;
ll ans[N],sum[N*4];
vector<pii> vec[N];

void build(int k,int l,int r){
	mn[k]=1;
	mns[k]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void add(int k,int v){
	tg[k]+=v; mn[k]+=v;
}
void addv(int k,int v){
	atg[k]+=v;
	sum[k]+=1ll*v*mns[k];
}
void pushdown(int k){
	if (tg[k]){
		add(k*2,tg[k]);
		add(k*2+1,tg[k]);
		tg[k]=0;
	}
	if (atg[k]){
		if (mn[k]==mn[k*2]) addv(k*2,atg[k]);
		if (mn[k]==mn[k*2+1]) addv(k*2+1,atg[k]);
		atg[k]=0;
	}
}
void pushup(int k){
	mn[k]=min(mn[k*2],mn[k*2+1]);
	sum[k]=sum[k*2]+sum[k*2+1];
	mns[k]=0;
	if (mn[k*2]==mn[k])
		mns[k]+=mns[k*2];
	if (mn[k*2+1]==mn[k])
		mns[k]+=mns[k*2+1];
}
void change(int k,int l,int r,int x,int y,int v){
	//cout<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<v<<endl;
	if (l==x&&r==y) return add(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	pushup(k);
}
ll ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return sum[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	scanf("%d",&Q);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[y].PB(pii(x,i));
	}
	build(1,1,n);
	For(i,1,n){
		for (;t1&&a[i]>=a[q1[t1]];--t1)
			change(1,1,n,q1[t1-1]+1,q1[t1],a[i]-a[q1[t1]]);
		for (;t2&&a[i]<=a[q2[t2]];--t2)
			change(1,1,n,q2[t2-1]+1,q2[t2],a[q2[t2]]-a[i]);
		q1[++t1]=q2[++t2]=i;
		//cout<<i<<endl;
		change(1,1,n,1,i,-1);
		//cout<<mn[1]<<' '<<mns[1]<<endl;
		if (mn[1]==0) sum[1]+=mns[1],atg[1]++;
		for (auto j:vec[i])	ans[j.se]=ask(1,1,n,j.fi,i);
	}
	For(i,1,Q)
		printf("%lld\n",ans[i]);
}