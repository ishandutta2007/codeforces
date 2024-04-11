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
int n,sz[N*4];
int tp[N],v[N],q[N];
ll s[N*4];
void change(int k,int l,int r,int p,int v){
	sz[k]+=v; s[k]+=q[p]*v;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
}
ll ask(int k,int l,int r,int w){
	if (l==r) return 1ll*min(w,sz[k])*q[l];
	int mid=(l+r)/2;
	if (sz[k*2+1]<=w)
		return ask(k*2,l,mid,w-sz[k*2+1])+s[k*2+1];
	return ask(k*2+1,mid+1,r,w);
}
map<int,int> mp;
void wzp(int v){
	auto it=mp.begin();
	for (;it->se==0;){
		int p=(it++)->fi;
		mp.erase(p);
	}
	change(1,1,n,it->fi,v);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&tp[i],&v[i]);
		q[i]=abs(v[i]);
	}
	sort(q+1,q+n+1); 
	ll sum=0,s=0,ss=0;
	For(i,1,n){
		if (s) wzp(1);
		int p=lower_bound(q+1,q+n+1,abs(v[i]))-q;
		if (v[i]>0){
			sum+=q[p]; s+=tp[i]; ss++;
			change(1,1,n,p,1);
			if (tp[i]) ++mp[p];
		}
		else{
			sum-=q[p]; s-=tp[i]; ss--;
			change(1,1,n,p,-1);
			if (tp[i]) --mp[p];
		}
		if (s) wzp(-1);
		printf("%lld\n",sum+ask(1,1,n,max(0ll,min(ss-1,s))));
	}
}