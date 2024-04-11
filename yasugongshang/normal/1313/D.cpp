#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int N=100005;
PI a[N];
int dp[N][1<<8|3],n,m,cnt[300],q[20];
vector<int> v[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	For(i,1,255)cnt[i]=cnt[i>>1]^(i&1);
	n=read(); read(); read();
	int tt=0; 
	For(i,1,n){
		a[i].fi=read(); a[i].se=read()+1;
	}
	sort(a+1,a+n+1);
	Rep(i,n,1){
		for(int j=i;j<=n&&a[i].se>a[j].fi;j++){
			v[j].pb(a[i].se);
		}
	}
	For(i,0,n+1)For(j,0,(1<<8)-1)dp[i][j]=0;
	a[n+1].fi=2e9;
	For(i,1,n){
		int t=v[i].size();
		Rep(j,(1<<t)-1,0)dp[i][j]=dp[i][j/2];
		For(j,0,(1<<t)-1){
			int dq=0,zt=0,tot=1; q[0]=a[i].fi;
			For(k,0,t-1)if(v[i][k]>a[i+1].fi){
				zt|=(j>>k&1)<<dq;
				dq++;
			}else if(j>>k&1)q[tot++]=v[i][k];
			sort(q,q+tot);
			q[tot]=a[i+1].fi;
			For(k,0,tot-1)dp[i][j]+=(cnt[j]^(k&1))*(q[k+1]-q[k]);
			//For(k,0,tot-1)wri(q[k]); puts("");
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<t<<" "<<dp[3][3]<<endl;
			dp[i+1][zt]=max(dp[i+1][zt],dp[i][j]);
		}
	}
	cout<<dp[n+1][0]<<endl;
}