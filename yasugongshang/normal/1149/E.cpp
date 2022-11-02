#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
int h[N],dp[N],vis[N],to[N],rd[N],q[N];
vector<int> f[N],g[N];
int main(){
	int n=read(),m=read();
	For(i,1,n)h[i]=read();
	For(i,1,m){
		int s=read(),t=read();
		f[s].pb(t); g[t].pb(s);
		rd[s]++;
	}
	For(i,1,n)if(!rd[i])q[++*q]=i;
	For(i,1,*q){
		int t=q[i];
		for(auto j:f[t])vis[dp[j]]=1;
		for(int j=0;;j++)if(!vis[j]){dp[t]=j; to[dp[t]]^=h[t]; break;}
		for(auto j:f[t])vis[dp[j]]=0;
		for(auto j:g[t])if(--rd[j]==0)q[++*q]=j;
	}
	Rep(i,n,0)if(to[i]){
		puts("WIN");
		For(j,1,n)if(dp[j]==i&&(h[j]^to[i])<h[j]){
			h[j]^=to[i];
			for(auto k:f[j]){
				h[k]^=to[dp[k]]; to[dp[k]]=0;
			}
			break;
		}
		For(i,1,n)wri(h[i]); puts("");
		return 0;
	}
	puts("LOSE");
}