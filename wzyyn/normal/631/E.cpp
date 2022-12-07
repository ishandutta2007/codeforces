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
int n,a[N];
ll sum[N];
struct Convex{
	int top;
	pll a[N];
	bool check(){
		assert(a[top].fi>=a[top-1].fi);
		assert(a[top-1].fi>=a[top-2].fi);
		pll f1(a[top].fi-a[top-1].fi,a[top].se-a[top-1].se);
		pll f2(a[top].fi-a[top-2].fi,a[top].se-a[top-2].se);
		return 1ll*f1.se*f2.fi>1ll*f2.se*f1.fi;
	}
	void add(ll k,ll b){
		a[++top]=pll(k,b);
		for (;top>2&&check();--top)
			a[top-1]=a[top];
	}
	ll Func(pll x,ll y){
		return 1ll*x.fi*y+x.se;
	}
	ll ask(ll x){
		ll res=-(1ll<<60);
		if (top==1)
			return Func(a[1],x);
		int l=1,r=top-1;
		while (l<=r){
			int mid=(l+r)/2;
			ll v1=Func(a[mid],x);
			ll v2=Func(a[mid+1],x);
			res=max(res,max(v1,v2));
			v1>=v2?r=mid-1:l=mid+1;
		}
		return res;
	}
	void clear(){
		top=0;
	}
}Hull;
int main(){
	ll del=0,ans=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) sum[i]=sum[i-1]+a[i];
	For(i,1,n) ans+=1ll*a[i]*i;
	//cout<<ans<<endl;
	Hull.clear();
	For(i,2,n){
		Hull.add(i-1,-sum[i-2]);
		del=max(del,sum[i-1]-1ll*a[i]*i+Hull.ask(a[i]));
		//cout<<del<<endl;
	}
	//-10+25-5
	Hull.clear();
	Rep(i,n-1,1){
		Hull.add(-(i+1),-sum[i+1]);
		del=max(del,Hull.ask(-a[i])-1ll*a[i]*i+sum[i]);
	}
	cout<<del+ans<<endl;
}