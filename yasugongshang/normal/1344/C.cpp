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
const int N=200005;
int n,m,mn[N],ans;
void GG(){
	puts("-1"); exit(0);
}
struct da{
	vector<int> e[N];
	int rd[N],dp[N];
	void ins(int x,int y){
		e[x].pb(y); rd[y]++;
	}
	void solve(){
		queue<int> q;
		For(i,1,n)dp[i]=i;
		For(i,1,n)if(!rd[i])q.push(i);
		while(q.size()){
			int t=q.front(); q.pop();
			for(auto i:e[t]){
				dp[i]=min(dp[i],dp[t]);
				if(--rd[i]==0)q.push(i);
			}
		}
		For(i,1,n)if(rd[i])GG();
		For(i,1,n)mn[i]=min(mn[i],dp[i]);
	}
}f,g;
int main(){
	n=read(),m=read();
	For(i,1,n)mn[i]=i;
	For(i,1,m){
		int x=read(),y=read();
		f.ins(x,y);
		g.ins(y,x);
	}
	f.solve();
	g.solve();
	For(i,1,n)if(mn[i]==i)ans++;
	writeln(ans);
	For(i,1,n)putchar(mn[i]==i?'A':'E');
}