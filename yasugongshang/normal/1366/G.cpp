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
const int N=10005,inf=1e9;
int dp[N][N],mn[N<<1],a[N<<1];
char s[N],t[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	s[++n]='#'; t[++m]='#';
	For(i,1,n)dp[i][0]=inf;
	For(j,1,m){
		int dq=10003,zt=0;
		For(i,0,20006)mn[i]=a[i]=inf;
		if(j==1)mn[dq]=a[dq]=0;
		For(i,1,n){
			if(s[i]==t[j]){
				dp[i][j]=mn[dq]+zt;
			}else{
				dp[i][j]=inf;
			}
			//if(j==1)cout<<dp[i][j]<<" "<<i<<" "<<j<<" "<<zt<<" "<<a[dq]<<" "<<mn[dq]<<endl;
			if(s[i]=='.'){
				dq++; zt--; a[dq]=min(a[dq],a[dq-1]+2); mn[dq]=min(mn[dq],a[dq-1]+2);
			}else{
				dq--; zt++; mn[dq]=min(mn[dq+1],a[dq]=(dp[i][j-1]-zt)); 
			}
		}
	}
	int ans=dp[n][m];
	cout<<ans<<endl;
}

/*
b.b..b..b...b.bbb
b

*/