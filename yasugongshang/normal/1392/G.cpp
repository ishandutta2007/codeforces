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
#define SZ(x) ((int)(x.size()))
#define re resize
#define PB pop_back
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
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int K=22,M=1<<20|3,inf=1e9,N=1000005;
char s[K],t[K];
int n,m,k,dp[K][M],p[K],ZT[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read(); m=read(); k=read();
	scanf("%s%s",s,t);
	For(i,0,k-1){
		s[i]-='0'; t[i]-='0';
	}
	For(i,0,k)For(j,0,(1<<k)-1)dp[i][j]=inf;
	For(i,0,k-1)p[i]=i;
	For(i,1,n){
		int x=read()-1,y=read()-1;
		int zt=0;
		For(j,0,k-1){
			zt|=s[p[j]]<<j;
		}
		dp[0][zt]=min(dp[0][zt],i-1);
		For(j,0,k-1)if(p[j]==x||p[j]==y)p[j]^=x^y;
		For(j,0,k-1){
			ZT[i]|=t[p[j]]<<j;
			//wri(p[j]);
		}//puts("dadfafa");
	}
	For(i,1,k)For(j,0,(1<<k)-1)For(o,0,k-1){
		dp[i][j]=min(dp[i][j],dp[i-1][j^(1<<o)]);
	}
	int ans=inf;
	For(i,1,n){
		For(j,0,k)if(i-dp[j][ZT[i]]>=m)ans=min(ans,j);
	}
	writeln(k-ans);
	For(i,1,n){
		if(i-dp[ans][ZT[i]]>=m){
			cout<<dp[ans][ZT[i]]+1<<" "<<i<<endl; return 0;
		}
	}
}