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
#define ld long double
int n,m,a[N],s[N];
ld dp[N][105],fac[N*5+100],ans;
inline ld c(int a,int b){
	return fac[a]/fac[b]/fac[a-b];
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){dp[i][s[i]=a[i]=read()]=1; ans+=a[i]==0;}
	fac[0]=1; for(int i=1;i<N*5+100;i++)fac[i]=fac[i-1]*i;
	m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),k=read(); 
		ans-=dp[u][0]; 
		for(int j=0;j<=a[u];j++){
			ld t=dp[u][j]; dp[u][j]=0;
			for(int l=0;l<=k&&l<=j;l++)if(s[u]-j>=k-l){
				ld jj=t*c(j,l)*c(s[u]-j,k-l)/c(s[u],k);
				//cout<<c(j,l)<<" "<<c(s[u]-j,k-l)<<" "<<c(s[u],k)<<" "<<s[u]-j<<" "<<k-l<<endl;
				//if(i==2&&j==2&&l==2)cout<<jj<<endl;
				dp[u][j-l]+=jj;
			}
		}
		s[u]-=k; s[v]+=k;
		ans+=dp[u][0]; 
		printf("%.10lf\n",(double)ans);
	}
}