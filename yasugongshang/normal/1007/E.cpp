#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define int ll
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
const int N=205;
const ll inf=1e18;
ll n,t,k,S[N],s[N],a[N],b[N],c[N],f[N][N][2],g[N][N][2];
ll dfs(int m,int n,int id);
ll Dfs(int m,int n,int id){
	if(g[m][n][id]!=-1)return g[m][n][id]; 
	ll sum=m*s[n-1]+(id?S[n-1]:s[n-1]),ans=-inf;
	if(dfs(m,n-1,id)>=0&&(m+1)*b[n]+(id?a[n]:0)<=c[n]&&(sum+k-1)/k*k<=m*s[n]+(id?S[n]:s[n]))ans=m*s[n]+(id?S[n]:s[n])-(sum+k-1)/k*k;
	//cout<<m<<" "<<n<<" "<<id<<" "<<ans<<endl;
	for(int i=0;i<m;i++){
		ll t=Dfs(i,n,id);
		if(t<0)continue; if(t%k+(m-i)*b[n]>c[n])continue;
		t+=(m-i)*b[n]; t=min(t,t-(t-c[n]+k-1)/k*k);
		ll sum=(m-i)*s[n-1];
		if(dfs(m-i-1,n-1,0)>=0&&(sum+k-1)/k*k-sum<=t)ans=max(ans,t-((sum+k-1)/k*k-sum));
	}
	return g[m][n][id]=ans;
}
ll dfs(int m,int n,int id){
	if(m==0||n==0)return id?S[n]+s[n]:s[n];
	if(f[m][n][id]!=-1)return f[m][n][id];
	ll ans=-inf;
	for(int i=1;i<=m;i++)if((m-i+1)*b[n]<=c[n]){
		ll t=Dfs(i-1,n,id); if(t<0)continue; //cout<<Dfs(i-1,n,id)<<" "<<i-1<<" "<<n<<" "<<id<<endl;
		if(t%k+(m-i+1)*b[n]>c[n])continue; t+=(m-i+1)*b[n];
		//m-i+1)*b[n] 
		ans=max(ans,dfs(m-i,n-1,0)+min((ll)t,t-(t-c[n]+k-1)/k*k));	
	}
	ll zz=b[n]*m+(id?a[n]:0)+b[n];

	if(zz<=c[n])ans=max(ans,dfs(m,n-1,id)+zz);
	return f[m][n][id]=ans;
}
signed main(){
	memset(f,-1,sizeof(f)); memset(g,-1,sizeof(g));
	n=read(),t=read(),k=read(); ll yq=0;
	for(int i=1;i<=n+1;i++){
		if(i<=n){a[i]=read(); b[i]=read(); c[i]=read(); } else {a[i]=1e18; c[i]=2e18; b[i]=0;} a[i]-=b[i];
		S[i]=S[i-1]+a[i]+b[i]; s[i]=s[i-1]+b[i]; yq+=a[i]+b[i]*(t+1);
		assert(a[i]<=c[i]&&b[i]<=c[i]);
	}
	//cout<<dfs(t,n+1,1)<<endl;
	assert((yq-dfs(t,n+1,1))%k==0);
	cout<<(yq-dfs(t,n+1,1))/k<<endl;
}
/*
2 4 11
0 1 3
0 13 14

g[i][j]ijj 
f[i][j][k]Aiij 
g[i][j]0ij 
*/