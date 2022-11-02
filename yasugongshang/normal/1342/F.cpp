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
const int N=18,M=1<<15|2,inf=1e9;
int dp[M][N][N],h[M][N],n,a[N],s[M],fa[N],bj[N];
 
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		n=read();
		For(i,0,n-1)a[i]=read();
		For(i,0,(1<<n)-1)For(j,0,n-1){
			h[i][j]=n;
			Rep(k,n-1,j)if(i>>k&1)h[i][j]=k;
			if(i>>j&1)s[i]=s[i^(1<<j)]+a[j];
		}
		For(i,0,(1<<n)-1)For(j,0,n)For(k,0,n)dp[i][j][k]=inf;
		dp[0][0][0]=0;
		For(i,0,(1<<n)-1){
			For(j,0,n-1)For(k,0,n-1)if(dp[i][j][k]<inf){
			//dp[i][j][k]ijk 
				
				int zt=((1<<n)-1)^i;
				for(int o=zt;o;o=(o-1)&zt)if(s[o]>dp[i][j][k]){
					dp[i|o][j+1][h[o][k]]=min(dp[i|o][j+1][h[o][k]],s[o]);
				}
			}
		}
		int zt=(1<<n)-1,p,q;
		For(i,0,n)For(j,0,n-1)if(dp[zt][i][j]<inf){
			p=i; q=j;
		}
		writeln(n-p);
		while(zt){
			//cout<<zt<<" "<<p<<" "<<q<<endl;
			for(int i=zt;i;i=(i-1)&zt){
				int f=0;
				For(j,0,n-1)if(s[i]==dp[zt][p][q]&&s[i]>dp[i^zt][p-1][j]&&h[i][j]==q){
					For(o,0,n-1)if(i>>o&1)fa[o]=q;
					zt^=i; p--; q=j; f=1; break;
				}
				if(f)break;
			}
		}
		//For(i,0,n-1)wri(fa[i]); puts("fsag");
		For(i,0,n-1)bj[i]=i+1;
		For(i,0,n-1)if(fa[i]!=i){
			wri(bj[i]); writeln(bj[fa[i]]);
			For(k,i+1,n-1)bj[k]--;
		}
	}
}