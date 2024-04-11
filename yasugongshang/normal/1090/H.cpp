#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
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
const int N=200005,K=18;
int n,bit[N],dp[K][N];
char s[N];
#define get(x,y) ((y)>n?0:dp[x][y])
int main(){
	int n=read();
	scanf("%s",s);
	for(int i=1;i<=n;i++){
		if(s[i]!=s[i-1])bit[i]=s[i]!=s[i-1];
	}
	for(int i=0;(1<<i)<=n;i++){
		for(int j=n;j;j--)dp[i][j]=bit[j]+get(i,j+(2<<i));
	}
	int Tq=read();
	while(Tq--){
		int l=read(),r=read()+1;
		int ans=0;
		for(int i=0;(1<<i)<r-l;i++){
			int x=get(i,l+(1<<i))-get(i,r+(1<<i));
			int sum=(r-l)>>(i+1);
			ans+=min(x,sum-x);
		}
		writeln((ans+1)/2);
	}
}
/*
8
01000000
3
0 7
2 5
0 3

*/