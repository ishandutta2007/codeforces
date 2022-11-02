#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
const int N=3005,B=11,mod=998244353;
const ll mod2=(ll)mod*mod*7;
int a[N],ycl[N];
ll F[N],G[N];
int vis[N];
inline void add(int &a,int b){
	a=a+b>=mod?a+b-mod:a+b;
}
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	int n=read(),c=read();
	For(i,1,n)a[i]=read();
	if(c>B){
		static ll dp[N][N/B+2],f[N];
		dp[0][0]=1;
		For(i,ycl[0]=1,n)ycl[i]=ycl[i-1]*2%mod;
		For(i,0,n){G[i]=ycl[i]-1; F[i]=ksm(G[i],mod-2);}
		For(i,c,n){
			memset(vis,0,sizeof(vis));
			int m=i/c,cnt=1;
			ll xs=1;
			Rep(j,i,1){
				if(a[j]!=a[i]){if(vis[a[j]])xs=xs*F[vis[a[j]]]%mod; else cnt++; vis[a[j]]++; xs=xs*G[vis[a[j]]]%mod;}
				if(cnt<c)continue;
				f[j]=(f[j]+xs*ycl[n-i])%mod; //if(i==5)cout<<j<<" "<<a[j]<<" "<<vis[2]<<" "<<i<<" "<<ycl[n-i]<<" "<<xs<<endl;
				For(k,1,m){dp[i][k]+=dp[j-1][k-1]*xs; if(dp[i][k]>=mod2)dp[i][k]-=mod2;}
			}
			For(j,1,m)dp[i][j]%=mod;
		}
		//For(i,1,n)wri(f[i]);
		int m=n/c;
		For(i,0,n)if(i>m)wri(0);
		else{
			int ans=i?0:mod-1;
			For(j,0,n)ans=(ans+dp[j][i]*(ycl[n-j]-f[j+1]))%mod;
			wri((ans+mod)%mod);
		}
	}else{
		static int dp[2][N][1<<B|2];
		For(i,0,n-1)a[i]=a[i+1]-1;
		dp[0][0][0]=1;
		For(i,0,n-1){
			int m=i/c;
			For(j,0,m){
				add(dp[i&1][j+1][0],dp[i&1][j][(1<<c)-1]); dp[i&1][j][(1<<c)-1]=0;
				For(k,0,(1<<c)-2){
					add(dp[i&1^1][j][k|(1<<a[i])],dp[i&1][j][k]);
					add(dp[i&1^1][j][k],dp[i&1][j][k]);
					dp[i&1][j][k]=0;
				}
			}
		}
		int m=n/c;
		For(i,0,n)if(i<=m){
			add(dp[n&1][i+1][0],dp[n&1][i][(1<<c)-1]); 
			int ans=i?0:mod-1;
			For(j,0,(1<<c)-2)add(ans,dp[n&1][i][j]);
			wri(ans);
		}else wri(0);
	}
}