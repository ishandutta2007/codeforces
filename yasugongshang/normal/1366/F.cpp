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
const int N=2005,mod=1e9+7,inf=1e18;
PI q[N];
int u[N],v[N];
ll mx[N],d[N][N],w[N];
ll yx(PI a,PI b){
	return (a.se-b.se)/(b.fi-a.fi);
}
ll sum(ll x){
	return x*(x+1)/2%mod;
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read(),m=read(),Q=read();
	For(i,1,m){
		u[i]=read(); v[i]=read(); w[i]=read();
		mx[u[i]]=max(mx[u[i]],w[i]);
		mx[v[i]]=max(mx[v[i]],w[i]);
	}
	For(i,1,n)For(j,0,n)d[j][i]=-inf;
	d[0][1]=0;
	For(i,1,n){
		For(j,1,m){
			d[i][v[j]]=max(d[i-1][u[j]]+w[j],d[i][v[j]]);
			d[i][u[j]]=max(d[i-1][v[j]]+w[j],d[i][u[j]]);
		}
	}
	ll ans=0;
	For(i,1,n){
		ll b=-inf,mmx=0;
		For(j,0,n)if(d[j][i]>=0)b=max(b,d[j][i]-j*mx[i]);
		q[i]=mp(mx[i],b);
		For(j,1,n)mmx=max(mmx,d[i][j]);
		if(i<=Q)ans+=mmx;
	//cout<<i<<" "<<mmx<<" "<<i*1890-mmx<<" "<<ans<<endl;
	}
	sort(q,q+n+1);
	int top=0;
	For(i,1,n){
		while(top&&q[top].fi<=q[i].fi&&q[top].se<=q[i].se)top--;
		while(top>=2&&yx(q[top],q[top-1])>=yx(q[i],q[top]))top--;
		q[++top]=q[i];
	}
	For(i,1,top){
		//cout<<q[i].fi<<" "<<q[i].se<<endl;
		int l=i==1?n:max((ll)n,yx(q[i],q[i-1])),r=i==top?Q:min((ll)Q,yx(q[i+1],q[i]));
		if(l>=r)continue;
		ans+=q[i].se%mod*(r-l)%mod+sum(r)*q[i].fi-sum(l)*q[i].fi;
		//cout<<l<<" "<<r<<" "<<q[i].fi<<" "<<q[i].se<<endl;
		ans%=mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
}