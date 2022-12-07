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
int t[N],n,a[N],p[N];
int v[N*4],S[N*4];
ll SS[N*4];
void change(int x){
	for (;x<=n;x+=x&(-x)) ++t[x];
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}

void build(int k,int l,int r){
	S[k]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void erase(int k,int l,int r,int p){
	--S[k];
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) erase(k*2,l,mid,p);
	else erase(k*2+1,mid+1,r,p);
	SS[k]=SS[k*2]+SS[k*2+1]+1ll*v[k*2]*S[k*2+1];
}
void change(int k,int l,int r,int p){
	++v[k];
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	SS[k]=SS[k*2]+SS[k*2+1]+1ll*v[k*2]*S[k*2+1];
}
ll ask(int k,int l,int r,int lim,int val){
	if (l==r){
		if (!S[k]) return 0;
		return min(val,lim-val);
	}
	int mid=(l+r)/2;
	if (min(val+v[k*2],lim-val-v[k*2])==val+v[k*2]){
		ll ans=SS[k*2]+1ll*S[k*2]*val;
		return ans+ask(k*2+1,mid+1,r,lim,val+v[k*2]);
	}
	else{
		ll ans=-SS[k*2+1]+1ll*S[k*2+1]*(lim-val-v[k*2]);
		return ans+ask(k*2,l,mid,lim,val);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),p[a[i]]=i;
	build(1,1,n);
	ll ans=0;
	For(i,1,n){
		ans+=i-1-ask(p[i]);
		change(p[i]);
		erase(1,1,n,p[i]);
		change(1,1,n,p[i]);
		printf("%lld ",ans+ask(1,1,n,i,0));
	}
}
/*
v[N],S[N],SS[N];
*/