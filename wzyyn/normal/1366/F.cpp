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
const int mo=1000000007;
const int N=2005;
int n,m,Q,rt,ans;
int x[N],y[N],v[N];
ll f[N][N],co[N];
int ls[N],rs[N],t[N],nd;
int cmp(int x,int y,int p){
	if (!x||!y) return !y;
	return (co[x]+1ll*v[x]*p)>(co[y]+1ll*v[y]*p);
}
void insert(int &k,int l,int r,int p){
	if (!k) return t[k=++nd]=p,void(0);
	int mid=(l+r)/2;
	if (cmp(p,t[k],mid)) swap(t[k],p);
	if (cmp(p,t[k],l)) insert(ls[k],l,mid,p);
	if (cmp(p,t[k],r)) insert(rs[k],mid+1,r,p);
}
int ask(int &k,int l,int r,int p){
	if (!k) return 0;
	int mid=(l+r)/2,v;
	if (p<=mid) v=ask(ls[k],l,mid,p);
	else v=ask(rs[k],mid+1,r,p);
	return cmp(t[k],v,p)?t[k]:v;
}
int Func(int x,int l,int r){
	//cout<<x<<' '<<l<<' '<<r<<' '<<v[x]<<' '<<co[x]<<endl;
	int ans=0;
	ans=1ll*(co[x]%mo+mo)*(r-l+1)%mo;
	ans=(ans+1ll*(r-l+1)*(l+r)/2%mo*v[x])%mo;
	return ans;
}
void Eiheihei(){
	For(i,1,m) insert(rt,1,Q,i);
	int p=n+1;
	for (;p<=Q;){
		int l=p,k=1;
		int v=ask(rt,1,Q,l);
		for (;p+k<=Q&&ask(rt,1,Q,p+k)==v;k<<=1);
		p+=k>>1; k>>=1;
		for (;k;k>>=1)
			if (p+k<=Q&&ask(rt,1,Q,p+k)==v) p+=k;
		ans=(ans+Func(v,l,p))%mo;
		p++;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,m) scanf("%d%d%d",&x[i],&y[i],&v[i]);
	memset(f,233,sizeof(f)); f[0][1]=0;
	For(i,1,n) For(j,1,m){
		f[i][y[j]]=max(f[i][y[j]],f[i-1][x[j]]+v[j]);
		f[i][x[j]]=max(f[i][x[j]],f[i-1][y[j]]+v[j]);
	}
	memset(co,233,sizeof(co));
	For(i,1,min(n,Q)){
		ll v=0;
		For(j,1,n) v=max(v,f[i][j]);
		ans=(ans+v)%mo;
	}
	For(i,1,n) For(j,1,m){
		co[j]=max(co[j],f[i][y[j]]-1ll*i*v[j]);
		co[j]=max(co[j],f[i][x[j]]-1ll*i*v[j]);
	}
	Eiheihei();
	cout<<ans<<endl;
}