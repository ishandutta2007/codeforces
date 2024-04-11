#include<bits/stdc++.h>

using namespace std;

const int N=300005;
int n,Q,k;
long long ans[N];
int a[N],b[N],q[N];
vector<pair<int,int>> op[N];

int tg[N*4],sz[N*4];
long long sum[N*4];

void build(int k,int l,int r){
	tg[k]=-1;
	sz[k]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void upd(int k,int v){
	sum[k]=1ll*sz[k]*v;
	tg[k]=v;
}
void pushdown(int k){
	if (tg[k]!=-1){
		upd(k*2,tg[k]);
		upd(k*2+1,tg[k]);
		tg[k]=-1;
	}
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y)
		return upd(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	sum[k]=sum[k*2]+sum[k*2+1];
}
long long ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y)
		return sum[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}

int c[N];
void solve(int p){
	int m=(n-p)/k+1;
	build(1,1,m);
	c[m+1]=-1;
	int t=1; q[1]=m+1;
	for (int i=(n-p)/k*k+p;i>=p;i-=k){
		int id=(i-p)/k+1;
		c[id]=b[i];
		for (;b[i]<c[q[t]];--t);
		change(1,1,m,id,q[t]-1,b[i]);
		q[++t]=id;
		for (auto j:op[i]){
			int r=(j.first-p)/k+1;
			int l=(i-p)/k+1;
			ans[j.second]+=ask(1,1,m,l,r);
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&Q,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int h=0,t=0;
	for (int i=1;i<=n;i++){
		for (;h!=t&&q[h+1]<=i-k-1;++h);
		for (;h!=t&&a[q[t]]>=a[i];--t);
		q[++t]=i;
		b[i]=a[q[h+1]];
	}
	for (int i=1;i<=Q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		int p=l+(r-l)/k*k;
		ans[i]=a[l];
		if (l+k<=p)	op[l+k].push_back(pair<int,int>(p,i));
	}
	for (int i=1;i<=k;i++)
		solve(i);
	for (int i=1;i<=Q;i++)
		printf("%lld\n",ans[i]);
}