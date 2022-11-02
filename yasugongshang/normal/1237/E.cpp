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
const int inf=1e9;
int dep,n;
ll dfs(int p,int q,int d,int rs){
	if(d==dep){
		if(rs&&q)return inf;
		else return q^1;
	}
	if(rs)return dfs(p<<1,1,d+1,0)+dfs(p<<1|1,q,d+1,1);
	else return dfs(p<<1|1,0,d+1,1)+dfs(p<<1,q^1,d+1,0);
}
int main(){
	n=read();
	if(n<=2){puts("1"); return 0;}
	while((1<<(dep+1))-1<=n)dep++; //cout<<dfs(2,1,2,0)<<endl;
	int ans=0;
	For(o,0,1)if(dfs(2,o,2,0)+dfs(3,(n&1)^o^1,2,1)==n-(1<<dep)+1)ans++;
	cout<<ans<<endl;
}