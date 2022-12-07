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
const int mo=1000000007;
int n,Q;
int a[N],w[N];
struct Tree{
	ll t[N*4];
	int nn;
	void init(int n){
		for (nn=1;nn<=n;nn<<=1);
	} 
	void change(int x,int v){
		for (x+=nn;x;x>>=1) t[x]+=v;
	}
	ll ask(int l,int r){
		ll ans=0;
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans+=t[l^1];
			if (r&1) ans+=t[r^1];
		}
		return ans;
	}
	int find(ll s){
		int k=1;
		for (;k<nn;)
			if (t[k*2]>=s)
				k*=2;
			else{
				s-=t[k*2];
				k=k*2+1;
			}
		return k-nn;
	}
}T1,T2;
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]),a[i]-=i;
	For(i,1,n) scanf("%d",&w[i]);
	T1.init(n);
	T2.init(n);
	For(i,1,n){
		T1.change(i,1ll*a[i]*w[i]%mo);
		T2.change(i,w[i]);
	}
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x<0){
			x*=-1;
			T1.change(x,1ll*a[x]*w[x]%mo*-1);
			T2.change(x,w[x]*-1);
			w[x]=y;
			T1.change(x,1ll*a[x]*w[x]%mo);
			T2.change(x,w[x]);
		}
		else{
			ll sl=T2.ask(1,x-1)+1;
			ll sr=T2.ask(1,y);
			ll sm=(sl+sr)/2;
			int m=T2.find(sm);
			int ans=0;
			ans=(ans+T2.ask(x,m-1)%mo*a[m])%mo;
			ans=(ans-T1.ask(x,m-1)%mo)%mo;
			ans=(ans+T1.ask(m+1,y)%mo)%mo;
			ans=(ans-T2.ask(m+1,y)%mo*a[m])%mo;
			cout<<(ans+mo)%mo<<endl;
		}
	}
}