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
const int N=80,inf=1e9;
struct data{
	int a,b,id;
}a[N];
bool cmp(data a,data b){
	return a.b<b.b;
}
int dp[N][N],ans[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		int n=read(),k=read();
		For(i,1,n){a[i].a=read(); a[i].b=read(); a[i].id=i;}
		sort(a+1,a+n+1,cmp);
		For(i,1,n+1)For(j,0,n)dp[i][j]=-inf;
		dp[1][0]=0;
		For(i,1,n){
			For(j,0,i){
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+j*a[i].b+a[i].a);
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(k-1)*a[i].b);
			}
		}
		int dq=k;
		vector<int> jb;
		Rep(i,n,1){
			if(dp[i][dq]==dp[i+1][dq]-(k-1)*a[i].b)jb.pb(a[i].id);
			else ans[dq--]=a[i].id;
		}
		writeln(k+jb.size()*2);
		For(i,1,k-1)wri(ans[i]);
		for(auto i:jb){
			wri(i); wri(-i);
		}
		writeln(ans[k]);
	}
}