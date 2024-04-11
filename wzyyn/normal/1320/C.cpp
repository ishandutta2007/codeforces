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
ll S[N*4],t[N*4],mx[N*4];
vector<int> vQ[N];
vector<pii> vC[N];
int n,m,Q,x,y;
void pushup(int k){
	mx[k]=max(mx[k*2],S[k*2]+mx[k*2+1]);
	S[k]=S[k*2]+S[k*2+1];
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		t[k]=max(t[k],1ll*v);
		mx[k]=max(mx[k],1ll*v);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	pushup(k);
}
void changev(int k,int l,int r,int p,int v){
	if (l==r){
		S[k]+=v;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) changev(k*2,l,mid,p,v);
	else changev(k*2+1,mid+1,r,p,v);
	pushup(k);
}
int main(){
	memset(t,233,sizeof(t));
	memset(mx,233,sizeof(mx));
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%d%d",&x,&y),vQ[x].PB(y);
	For(i,1,m) scanf("%d%d",&x,&y),change(1,0,N-1,x,-y);
	For(i,1,Q){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		vC[x].PB(pii(y,v));
	}
	ll ans=-(1ll<<60);
	For(i,0,N-1){
		for (auto j:vQ[i])
			ans=max(ans,mx[1]-j);
		for (auto j:vC[i]) changev(1,0,N-1,j.fi,j.se);
	}
	printf("%lld\n",ans);
}