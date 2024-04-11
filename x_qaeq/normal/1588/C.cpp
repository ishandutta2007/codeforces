//Coded by X_qaeq on 2021.11.14 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=300005;
namespace T1/*{{{*/
{
	ll T[N<<2];
	inline void build(int x,int l,int r)
	{
		T[x]=-1e18;if(l==r) return;
		build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r);
	}
	inline void modif(int x,int l,int r,int dw,ll dc)
	{
		if(l==r) return T[x]=dc,void();
		if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=max(T[x<<1],T[x<<1|1]);
		else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=max(T[x<<1],T[x<<1|1]);
	}
	inline int qry(int x,int l,int r,ll w)
	{
		if(l==r) return l;
		if(T[x<<1]>w) return qry(x<<1,l,(l+r)>>1,w);
		else return qry(x<<1|1,((l+r)>>1)+1,r,w);
	}
}/*}}}*/
namespace T2/*{{{*/
{
	ll T[N<<2];
	inline void build(int x,int l,int r)
	{
		T[x]=1e18;if(l==r) return;
		build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r);
	}
	inline void modif(int x,int l,int r,int dw,ll dc)
	{
		if(l==r) return T[x]=dc,void();
		if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
		else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
	}
	inline int qry(int x,int l,int r,ll w)
	{
		if(l==r) return l;
		if(T[x<<1]<w) return qry(x<<1,l,(l+r)>>1,w);
		else return qry(x<<1|1,((l+r)>>1)+1,r,w);
	}
}/*}}}*/
map<ll,vector<int> >id;int n,lf[N],a[N];ll s[N];
inline void solve()
{
	id.clear(),read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i+=2) a[i]=-a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	T1::build(1,1,n),T2::build(1,1,n);
	for(int i=n;i>=0;i--)
	{
		if(i&1) lf[i]=min(T1::qry(1,1,n,s[i]),T2::qry(1,1,n,s[i])),T2::modif(1,1,n,i,s[i]);
		else lf[i]=min(T1::qry(1,1,n,s[i]),T2::qry(1,1,n,s[i])),T1::modif(1,1,n,i,s[i]);
		//printf("lf %d\n",lf[i]);
	}
	ll rs=0;for(int i=n;i>=0;i--)
	{
		auto &vec=id[s[i]];
		int ps=vec.end()-lower_bound(vec.begin(),vec.end(),lf[i],greater<int>());
		rs+=ps,vec.push_back(i);
	}printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}