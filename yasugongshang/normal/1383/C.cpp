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
const int N=20,M=1<<20|3,NN=100005;
int n,fa[N],e[N],dp[M],cnt[M];
char a[NN],b[NN];
inline int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
int main(){    
	#ifdef Brollan
        freopen("1.in","r",stdin);
    #endif
	int T=read();
	while(T--){
		n=read(); 
		scanf("%s",a+1);
		scanf("%s",b+1);  
		mem(e);
		For(i,1,n){
			e[a[i]-'a']|=1<<(b[i]-'a');
		}
		For(i,0,N-1)if(e[i]>>i&1)e[i]-=1<<i;
		mem(dp);
		dp[0]=1; 
		For(i,1,(1<<N)-1){
			For(j,0,N-1)if((i>>j&1)&&!(e[j]&i))dp[i]|=dp[i^(1<<j)];
		}
		For(i,0,N-1)fa[i]=i;
		For(i,0,N-1)For(j,0,N-1)if(e[i]>>j&1)fa[gf(j)]=gf(i);
		int ans=2*N,mx=0;
		For(i,1,(1<<N)-1){
			cnt[i]=cnt[i>>1]+(i&1);
			if(dp[i])mx=max(mx,cnt[i]);
		}
		ans-=mx;
		For(i,0,N-1)ans-=fa[i]==i;
		cout<<ans<<endl;
	}
}
/*
a[i]x+b[i]=g^d[i]*(x+1)^c[i]
*/