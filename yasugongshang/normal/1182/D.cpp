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
const int N=100005;
int FA[N],dep[N],rt;
set<int> S[N];
vector<int> v[N];
void dfs(int p,int fa){
	//cout<<p<<" "<<dep[p]<<endl;
	if(dep[p]>dep[rt]){
		rt=p; 
	}
	FA[p]=fa; S[dep[p]].insert(v[p].size());
	for(auto i:v[p])if(i!=fa){
		dep[i]=dep[p]+1; 
		dfs(i,p);
	}
}
void GG(){
	puts("-1"); exit(0);
}
void ddd(int p,int fa){
	if(fa&&v[p].size()==1&&dep[p]<dep[rt])rt=p;
	if(fa&&v[p].size()!=2)return;
	for(auto i:v[p])if(i!=fa){
		dep[i]=dep[p]+1;
		ddd(i,p);
	}
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read(); dep[0]=-1;
	For(i,1,n-1){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	rt=0;
	dfs(1,0);
	int t=rt; dep[t]=rt=0;
	dfs(t,0);
	For(i,0,n)S[i].clear();
	Rep(i,(dep[rt]+1)/2,1)rt=FA[rt];
	t=rt; dep[t]=0; dep[0]=1e9; rt=0;
	ddd(t,0); if(rt)t=rt;dep[t]=0; 
	dfs(t,0);
	For(i,0,n)if(S[i].size()>1)GG();
	cout<<t<<endl;
}