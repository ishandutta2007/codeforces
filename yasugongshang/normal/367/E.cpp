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
const int mod=1000000007;
int n,m,x,dp[2][400][400];
inline void add(int &a,int b){
	a=a+b>=mod?a+b-mod:a+b;
}
int solve(int n,int m,int x){
	memset(dp,0,sizeof(dp)); dp[1][1][1]=1; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+1;j++)for(int k=1;k<=j;k++)dp[i&1^1][j][k]=0;
		for(int j=1;j<=m+1;j++){
			for(int k=1;k<=j;k++){
				add(dp[i&1^1][j][k],dp[i&1][j][k]);
				if(i!=x)add(dp[i&1^1][j+1][k],dp[i&1][j][k]);
				add(dp[i&1^1][j][k+1],dp[i&1][j][k]);
				//ccout<<dp[i&1][j][k]<<endl;
				if(i!=x)add(dp[i&1^1][j+1][k+1],dp[i&1][j][k]);
			}
		}
	}
	return dp[(n+1)&1][m+1][m+1];
}
int main(){
	m=read(); n=read(); x=read();
	if(m>n)puts("0");
	else {
		//cout<<solve(n,m,0)<<" "<<solve(n,m,x)<<endl;
		ll ans=(solve(n,m,0)-solve(n,m,x)+mod)%mod;
		for(int i=1;i<=m;i++)ans=ans*i%mod;
		cout<<ans<<endl;
	}
}