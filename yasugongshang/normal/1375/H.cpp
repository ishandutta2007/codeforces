#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=4100,M=N<<1,B=257;
vector<int> v[N],V[M];
vector<PI> ans;
vector<vector<int> > T[M];
int tot,nodecnt,a[N],n,q,rt[N],an[70000];
int ask(int nod,int l,int r){
	if(l==r)return l;
	l=lower_bound(V[nod].begin(),V[nod].end(),l)-V[nod].begin();
	r=upper_bound(V[nod].begin(),V[nod].end(),r)-V[nod].begin()-1;
	return l>r?0:T[nod][l][r];
}
int mer(int x,int y){
	if(!x||!y)return x|y;
	if(x==y)return x;
	//cerr<<x<<" "<<y<<endl;
	++tot;
	ans.pb(mp(x,y));
	return tot;
}
void dfs(vector<int> v,int l,int r,int &rt){//cerr<<l<<"fjz"<<r<<endl;
	rt=++nodecnt;
	int n=v.size(),ls,rs;
	if(n>1){
		vector<int> vl,vr;
		int mid=(l+r)>>1;
		for(auto i:v)if(a[i]<=mid)vl.pb(i); else vr.pb(i);
		dfs(vl,l,mid,ls); dfs(vr,mid+1,r,rs);
	}
	T[rt].resize(n);
	For(i,0,n-1){
		T[rt][i].resize(n);
		For(j,i,n-1){
			T[rt][i][j]=mer(ask(ls,v[i],v[j]),ask(rs,v[i],v[j]));
		}
	}
	V[rt]=v;
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read(); q=read();
	For(i,1,n)a[i]=read();
	tot=n;
	for(int i=0;i<=n;i+=B){
		vector<int> v;
		For(j,1,n)if(a[j]>=i&&a[j]<i+B){
			v.pb(j);
		}
		dfs(v,i,i+B,rt[i/B]);
	}
	
	For(i,1,q){
		int l=read(),r=read(),ans=0;
		For(i,0,n/B)ans=mer(ans,ask(rt[i],l,r));
		an[i]=ans;
	}
	writeln(tot);
	for(auto i:ans){
		wri(i.fi); writeln(i.se);
	}
	For(i,1,q)wri(an[i]);
}