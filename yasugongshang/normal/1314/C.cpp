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
const int N=1005,M=510000,K=26;
const ll inf=1e18;
int n,m,cnt=1,ti,ycl[N],q[M],ch[M][K];
ll dp[N][N],k;
char a[N];
vector<pair<int,int> > v[M];
void dfs(int p){
	//for(auto j:v[p])rk[j.fi][j.se]=ti;
	//if(p>1)cout<<p<<" "<<v[p][0].fi<<" "<<v[p][0].se<<endl;
	if(p>1)q[++ti]=p;
	For(i,0,K-1)if(ch[p][i]){
		dfs(ch[p][i]);
	}
}
int LCP(int x,int y){
	if(x==y)return n;
	int t=0;
	while(a[x+t]==a[y+t])t++;
	return t;
}
bool check(int x){
	int L=v[x][0].fi,R=v[x][0].se;
	ycl[n]=n+1;
	For(i,0,n-1){
		int t=LCP(L,i+1);
		if(t>=R-L+1)ycl[i]=i+R-L+1;
		else ycl[i]=a[i+t+1]>a[L+t]?i+t+1:n+1;
	}
	mem(dp);
	dp[0][0]=1;
	dp[0][1]--;
	For(i,0,m){
		For(j,1,n)dp[i][j]=min(dp[i][j-1]+dp[i][j],inf);
		For(j,0,n-1){
		//if(L==1&&R==2)cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			dp[i+1][ycl[j]]=min(dp[i+1][ycl[j]]+dp[i][j],inf);
		}
	}
	//cout<<L<<" "<<R<<" "<<dp[m][n]<<endl;
	return dp[m][n]>=k;
}
int main(){
	n=read(); m=read(); k=read(); 
	scanf("%s",a+1);
	For(i,1,n){
		int p=1;
		For(j,i,n){
			int t=a[j]-'a';
			if(!ch[p][t])ch[p][t]=++cnt;
			p=ch[p][t];
			v[p].pb(mp(i,j));
		}
	}
	dfs(1);
	int l=1,r=ti;
	while(l<r){
		int mid=(l+r)>>1; mid++;
		if(check(q[mid]))l=mid; else r=mid-1;
	}
	int L=v[q[l]][0].fi,R=v[q[r]][0].se;
	//cout<<L<<" "<<R<<" "<<v[15].size()<<endl;
	For(i,L,R)putchar(a[i]);
}