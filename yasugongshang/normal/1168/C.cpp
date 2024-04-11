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
const int N=300005,K=19;
int dp[N][K],s[K][K],a[N];
int main(){
	//freopen("std.in","r",stdin); freopen("my.out","w",stdout);
	int n=read(),q=read();
	For(i,1,n){
		a[i]=read();
		For(j,0,K-1)if(a[i]>>j&1){
			For(k,0,K-1)dp[i][k]=max(dp[i][k],s[k][j]);
			dp[i][j]=i;
		}
		For(j,0,K-1)if(a[i]>>j&1){
			For(k,0,K-1)s[k][j]=max(s[k][j],dp[i][k]);
		}
	}
	while(q--){
		int x=read(),y=read(),f=1;
		for(int i=0;i<K&&f;i++)if((a[x]>>i&1)&&x<=dp[y][i])f=0;
		if(f)puts("Fou"); else puts("Shi");
	}
}
/*
ijdp[i][j]
*/