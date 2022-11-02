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
const int N=2005,inf=1e8;
int dp[N][N];
char s[N],t[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		int n=read();
		scanf("%s%s",s+1,t+1);
		For(i,1,n){
			s[i]-='a'; t[i]-='a';
		}
		swap(s,t);
		For(i,0,n)For(j,0,n)dp[i][j]=inf;
		dp[0][0]=0;
		int to[26]; mem(to);
		For(i,0,n){
			if(i)to[s[i]]++; int dq[26];
			memcpy(dq,to,sizeof(to));
			For(j,0,n){
				if(j){dq[t[j]]--; if(dq[t[j]]<0)break;}
				if(s[i+1]==t[j+1])dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
				if(dq[t[j+1]])dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
				//cout<<i<<" "<<j<<" "<<dq[t[j+1]]<<" "<<dp[i][j]<<endl;
			}
		}
		cout<<(dp[n][n]>=inf?-1:dp[n][n])<<endl;
	}
}