#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
int n,m,t,a[N];
vector<int> dp[N];
signed main(){
	int T=read(); n=read(); m=read(); t=min((int)read(),min(n,m));
	while(T--){
		dp[0].resize(m+1);
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=0;i<=m;i++)dp[0][i]=0; int ans=0;
		for(int i=1;i<=n&&i<=m;i++){
			dp[i].resize(m+1);
			for(int j=0;j<=m;j++)dp[i][j]=1e9;
			for(int j=n;j;j--){
				int t=dp[i-1][a[j]-1];
				if(t==0){dp[i][a[j]]=j; continue;}
				if((t%n==0?n:t%n)<j)dp[i][a[j]]=min(dp[i][a[j]],(t-1)/n*n+j); else dp[i][a[j]]=min(dp[i][a[j]],(t-1)/n*n+n+j);
			}
			for(int j=1;j<=m;j++)dp[i][j]=min(dp[i][j-1],dp[i][j]);
			if(dp[i][m]<=t*n)ans=i; else break;
		}
		cout<<ans<<endl;
		
	}
}