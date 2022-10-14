#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
#define FF first
#define SS second
#define mid ((l+r)/2)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
const ll N = 5e5 + 50;
ll mi[4*N],lazy[4*N] = {0};

void pushd(ll p){
	lazy[p*2]+=lazy[p];
	lazy[p*2+1]+=lazy[p];
	mi[p]+=lazy[p];
	lazy[p] = 0;
}
ll query(ll p,ll l,ll r,ll ql,ll qr){
	//cout<<p<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<endl;
	if(l>=ql && r<=qr)return mi[p]+lazy[p];
	pushd(p);
	if(qr<=mid)return query(p*2,l,mid,ql,qr);
	if(ql>mid) return query(p*2+1,mid+1,r,ql,qr);
	return min(query(p*2,l,mid,ql,qr),query(p*2+1,mid+1,r,ql,qr));
}
void config(ll p,ll l,ll r,ll q,ll v){
	if(l==r){
		mi[p]=v;
		return;
	}
	if(q<=mid)config(p*2,l,mid,q,v);
	if(q>mid) config(p*2+1,mid+1,r,q,v);
	mi[p] = min(mi[p*2],mi[p*2+1]);
}
void change(ll p,ll l,ll r,ll ql,ll qr,ll v){
	if(l>=ql && r<=qr){
		lazy[p]+=v;
		return;
	}
	pushd(p);
	if(qr<=mid){
		change(p*2,l,mid,ql,qr,v);
	}else{
		if(ql>mid){
			change(p*2+1,mid+1,r,ql,qr,v);
		}else{
			change(p*2,l,mid,ql,qr,v);
			change(p*2+1,mid+1,r,ql,qr,v);
		}
	}
	mi[p] = min(mi[p*2]+lazy[p*2],mi[p*2+1]+lazy[p*2+1]);
}
ll n,q,p,w,v,l,r,ans[N],sz[N],globe = 0;
vector< pair< ll , pair< ll , ll > > > queries[N];
vector< pair<ll,ll> > G[N];
void dfs(ll num,ll ct){
	sz[num] = 1;
	if(G[num].size() == 0) config(1,1,n,num,ct);
	for(auto cw:G[num]){
		dfs(cw.first,ct+cw.second);
		sz[num]+=sz[cw.FF];
	}
}
void dfs2(ll num){
	for(auto que:queries[num]){
		//cout<<que.FF<<endl;
		ans[que.first] = query(1,1,n,que.SS.FF,que.SS.SS)+globe;
		//cout<<que.FF<<endl;
	}
	for(auto cw:G[num]){
		change(1,1,n,cw.FF,cw.FF+sz[cw.FF]-1,-2*cw.SS);
		globe+=cw.SS;
		dfs2(cw.FF);
		change(1,1,n,cw.FF,cw.FF+sz[cw.FF]-1,2*cw.SS);
		globe-=cw.SS;
	}
}
int main() {
	memset(mi,7,sizeof(mi));
	read(n);read(q);
	for(int i=2;i<=n;i++){
		read(p);read(w);
		G[p].push_back(make_pair(i,w));
	}
	dfs(1,0);
	for(int i=0;i<q;i++){
		read(v);read(l);read(r);
		queries[v].push_back(make_pair(i,make_pair(l,r)));
	}
//	cout<<233<<endl;
	dfs2(1);
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}