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
#define re resize
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
const int N=100005;
const ld eps=1e-9;
ld A[N],B[N],ans[N];
int n,m;
vector<ld> ab,f;
vector<int> g;
vector<PI> v[N];
void GG(){
	puts("NO"); exit(0);
}
void dfs(int p,int a,int b){
	if(!A[p]){
		A[p]=a; B[p]=b;
	}else if(A[p]!=a||B[p]!=b){
		if(A[p]==a)GG();
		ab.pb((ld)(b-B[p])/(A[p]-a)); return;
	}else return;
	f.pb(a*b); g.pb(p);
	for(auto i:v[p]){
		dfs(i.fi,-a,i.se-b);
	}
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read(); m=read();
	For(i,1,m){
		int s=read(),t=read(),w=read();
		v[s].pb(mp(t,w));
		v[t].pb(mp(s,w));
	}
	For(i,1,n)if(!A[i]){
		ab.clear(); f.clear(); g.clear();
		dfs(i,1,0);
		if(ab.size()){
			For(i,1,ab.size()-1)if(fabs(ab[i]-ab[i-1])>eps)GG();
			for(auto i:g)ans[i]=A[i]*ab[0]+B[i];
		}else{
			sort(f.begin(),f.end());
			ld x=-f[f.size()/2];
			for(auto i:g)ans[i]=A[i]*x+B[i];
		}
	}
	puts("YES");
	For(i,1,n-1)printf("%.10f ",(double)ans[i]); printf("%.10f",(double)ans[n]);
}