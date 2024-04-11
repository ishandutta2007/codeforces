#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define int ll
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
ll ans,B[N],G[N];
PI q[N<<1];
set<int> sb,sg;
vector<ll> s[N<<1];
void exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1; y=0; return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
ll inv(int a,int b){
	int x,y;
	exgcd(a,b,x,y);
	
	return (x+b)%b;
}
void solve(int n,int m,int t,int in,vector<int> s){
	if(!s.size()){puts("-1"); exit(0);}
	int to=0;
	for(auto i:s){
		q[to++]=mp((ll)(i/t)*in%(n/t)*m,i);
		//cout<<i/t*in%(n/t)*m<<" "<<i<<endl;
	}
	sort(q,q+to); to=unique(q,q+to)-q;
	For(i,0,to-1)if((q[(i+1)%to].fi-q[i].fi-m)%(n/t*m))ans=max(ans,q[i].se+(q[(i+1)%to].fi-q[i].fi-m+n/t*m)%(n/t*m));
}
signed main(){
	int n=read(),m=read();
	int b=read();
	For(i,1,b)B[i]=read();
	int g=read();
	For(i,1,g)G[i]=read();
	if(n<m){
		swap(n,m); swap(b,g); swap(B,G);
	}
	For(i,1,b)sb.insert(B[i]);
	For(i,1,g)sg.insert(G[i]);
	For(i,0,n-1)if(!sb.count(i)&&!sg.count(i)){
		ans=-1; break;
	}else if(i<m&&(!sg.count(i)||!sb.count(i)))ans=i;
	if(ans>=0){
		cout<<ans<<endl; return 0;
	}
	int t=__gcd(n,m),in=inv(m/t,n/t);
	if(t>200000){puts("-1"); return 0;}
	for(auto i:sb)s[i%t].pb(i);
	for(auto i:sg)s[i%t].pb(i);
	For(i,0,t-1)solve(n,m,t,in,s[i]);
	cout<<ans<<endl;
}