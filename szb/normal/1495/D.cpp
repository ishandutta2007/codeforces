#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define ld long double
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
#define	pb	push_back
#define mk	make_pair
#define pa	pair<ll,ll>
#define y1	y11111111111111
#define debug	puts("@@@@@@@@@@@@@@@@@@@@@@@")
ll read(){
	ll x=0,f=1;	char ch=getchar();	
	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)	putchar('-'),write(-x);
	else{
		if (x>=10)	write(x/10);
		putchar(x%10+'0');
	}
}
const ll mod=998244353,N=610;
vector<ll>g[N];
ll sm[N][N],dis[N][N],vis[N],q[N],n,m;
ll work(ll a,ll b){
	if (sm[a][b]>1)return 0;
	ll he=0,ta=0,ans=1;
	For(i,1,n)vis[i]=0;
	For(i,1,n)if (dis[a][i]+dis[i][b]==dis[a][b]){
		q[++ta]=i;
		vis[i]=1;
	}
	for(;he!=ta;){
		ll x=q[++he];
		rep(i,0,g[x].size()){
			ll to=g[x][i];
			if ((dis[to][a]-dis[x][a]==1)&&(dis[to][b]-dis[x][b]==1)){
				if (!vis[to]){
					q[++ta]=to;
				}
				++vis[to];
			}
		}
	}
	For(i,1,n)ans=ans*vis[i]%mod;
	return ans;
}
int main(){
	n=read();	m=read();
	For(i,1,n)For(j,1,n)if (i^j)dis[i][j]=1e9;
	For(i,1,m){
		ll a=read(),b=read();
		dis[a][b]=dis[b][a]=1;
		sm[a][b]=sm[b][a]=1;
		g[a].pb(b);	g[b].pb(a);
	}
	For(k,1,n)For(i,1,n)For(j,1,n){
		if (dis[i][k]+dis[k][j]==dis[i][j]){
			sm[i][j]=min(2ll,sm[i][k]*sm[k][j]+sm[i][j]);
		}else if (dis[i][k]+dis[k][j]<dis[i][j]){
			dis[i][j]=dis[i][k]+dis[k][j];
			sm[i][j]=min(2ll,sm[i][k]*sm[k][j]);
		}
	}
	For(i,1,n){
		For(j,1,n)write(work(i,j)),putchar(' ');
		puts("");
	}
}