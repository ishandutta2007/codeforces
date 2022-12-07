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
vector<pll> v,V[20];
ll m,x,c[20],n,q[100],ans;
ll mul(ll x,ll y,ll mo){
	ll t=x*y-(ll)((long double)x/mo*y)*mo;
	return (t%mo+mo)%mo;
}
ll power(ll x,ll y,ll mo){
	ll s=1;
	for (;y;y/=2,x=mul(x,x,mo))
		if (y&1) s=mul(s,x,mo);
	return s;
}
void divide(vector<pll> &vec,ll m){
	int tmp=0;
	for (int i=2;1ll*i*i<=m;i++)
		if (m%i==0){
			vec.PB(pll(i,0));
			for (;m%i==0;m/=i,++vec[tmp].se);
			++tmp;
		}
	if (m!=1)
		vec.PB(pll(m,1));
}
void solve(ll val){
	if (val==1){
		++ans;
		return;
	}
	ll phi=1,top=0,tmp=1,v=x%val;
	For(i,0,n-1) if (c[i]){
		phi*=::v[i].fi-1;
		//cout<<phi<<endl;
		for (auto j:V[i])
			For(k,1,j.se)
				q[++top]=j.fi;
		For(j,2,c[i]){
			phi*=::v[i].fi;
			q[++top]=::v[i].fi;
		}
	}
	//cout<<phi<<endl;
	For(i,1,top)
		if (power(v,phi/q[i],val)==1)
			tmp*=q[i],phi/=q[i];
	ans+=tmp;
	//cout<<val<<' '<<tmp<<' '<<phi<<endl;
}
void dfs(int x,ll val){
	if (x==n) return solve(val);
	for (c[x]=0;c[x]<=v[x].se;++c[x])
		dfs(x+1,val),val*=v[x].fi;
}
int main(){
	scanf("%lld%lld",&m,&x);
	divide(v,m);
	n=v.size();
	For(i,0,n-1) divide(V[i],v[i].fi-1);
	dfs(0,1);
	printf("%lld\n",ans);
}