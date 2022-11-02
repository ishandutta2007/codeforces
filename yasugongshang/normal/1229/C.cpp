#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
int val[N],cd[N],rd[N];
ll ans;
vector<int> e[N],v[N];
int main(){
	int n=read(),m=read();
	For(i,1,n)val[i]=i;
	For(i,1,m){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	For(i,1,n){
		for(auto j:v[i])if(val[j]<val[i])rd[i]++; else {cd[i]++; e[i].pb(j);}
	}
	For(i,1,n)ans+=(ll)cd[i]*rd[i];
	writeln(ans);
	int q=read();
	while(q--){
		int i=read();
		ans-=(ll)cd[i]*rd[i];
		cd[i]-=e[i].size(); rd[i]+=e[i].size();
		for(auto j:e[i]){
			ans-=cd[j];
			rd[j]--; 
			ans+=rd[j];
			cd[j]++; e[j].pb(i);
		}
		e[i].clear();
		writeln(ans);
	}
}