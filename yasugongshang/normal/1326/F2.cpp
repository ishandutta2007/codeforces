#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<int>
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=18;
poly Q[400];
map<poly,int> Map;
int tot,n,bit[1<<18|2],q[20];
char e[20][20];
ll f[1<<(N-1)|2],jdb[400],dp[20][20],sum[20];
void dfs(int rest,int dq,poly v){
	if(!rest){
		Q[++tot]=v; Map[v]=tot; return;
	}
	For(i,dq,rest){
		v.pb(i);
		dfs(rest-i,i,v);
		v.pop_back();
	}
}
int main(){
	#ifdef Brollan	
		freopen("1.in","r",stdin);
	#endif
	n=read();
	For(i,0,n-1){
		scanf("%s",e[i]);
		For(j,0,n-1)e[i][j]-='0';
	}
	poly v;
	dfs(n,1,v);
	mem(jdb);
	For(i,0,(1<<n)-1){
		bit[i]=bit[i>>1]+(i&1);
		mem(dp); mem(sum);
		int tt=0;
		For(j,0,n-1)if(i>>j&1)q[tt++]=j;
		For(j,0,tt-1)dp[0][j]=1;
		For(j,0,n-1)For(k,0,tt-1)For(l,0,tt-1)if(e[q[k]][q[l]])dp[j+1][l]=dp[j+1][l]+dp[j][k];
		For(i,0,n-1)For(j,0,tt-1)sum[i]+=dp[i][j];
		For(j,1,tot){
			ll ans=1;
			for(auto k:Q[j])ans*=sum[k-1];
			if((n-bit[i])&1)ans=-ans;
			jdb[j]+=ans;
			//cout<<i<<" "<<j<<" "<<ans<<" "<<jdb[j]<<endl;
		}
	}
	For(i,0,(1<<(n-1))-1){
		int dq=1;
		poly vv;
		For(j,0,n-1)if(i>>j&1){
			dq++;
		}else {vv.pb(dq); dq=1;}
		sort(vv.begin(),vv.end());
		//for(auto i:vv)wri(i); puts("");
		f[i]=jdb[Map[vv]];
		//cout<<i<<" "<<f[i]<<endl;
	}
	For(i,0,n-2)For(j,0,(1<<(n-1))-1)if(j>>i&1)f[j-(1<<i)]-=f[j];
	For(i,0,(1<<(n-1))-1)wri(f[i]);
}