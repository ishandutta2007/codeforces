#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
#define ld long double
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
const int N=2005,mod=1000000007;
int n,k,dp[N][N],ans;
int main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++)dp[1][i]=1;
	for(int i=1;i<k;i++){
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k+=j)dp[i+1][k]=(dp[i+1][k]+dp[i][j])%mod;
		}
	}
	for(int i=1;i<=n;i++)ans=(ans+dp[k][i])%mod;
	cout<<ans<<endl;
}