#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define fi first
#define se second
#define pa pair<ll,ll>
#define pb push_back
#define y1 y11111111111111
#define debug puts("@@@@@@@@@@@@@@@@@@@")
 
#define cpy(a,b) memcpy(a,b,sizeof(b))
inline ll read()
{
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
 
void write(ll x)
{
	if(x < 0) putchar('-'), x= -x;
	if(x > 9)write(x/10);
	putchar(x%10+'0');
}
const ll N=1000100;
vector<ll>g[N],w[N]; 
ll vis[N],d[N],id1[N],id2[N],x[N],y[N],sx,sy,tx,ty,n;
priority_queue<pa>q;
bool cmp1(ll a,ll b){
	return pa(x[a],y[a])<pa(x[b],y[b]);
}
bool cmp2(ll a,ll b){
	return pa(y[a],x[a])<pa(y[b],x[b]); 
}
void addedge(ll a,ll b){
	ll d=min(abs(x[a]-x[b]),abs(y[a]-y[b]));
	g[a].pb(b);	g[b].pb(a);
	w[a].pb(d);	w[b].pb(d);
}
int main(){
	read();		n=read();
	sx=read();	sy=read();	tx=read();	ty=read();
	For(i,1,n)	x[i]=read(),y[i]=read(),id1[i]=id2[i]=i;
	sort(id1+1,id1+n+1,cmp1);
	sort(id2+1,id2+n+1,cmp2);
	For(i,1,n-1){
		addedge(id1[i],id1[i+1]);
		addedge(id2[i],id2[i+1]); 
	}
	For(i,1,n){
		d[i]=min(abs(sx-x[i]),abs(sy-y[i]));
		q.push(pa(-d[i],i));
//		cout<<d[i]<<endl;
	}
	for(;!q.empty();){
		ll x=q.top().se;	q.pop();
		if (vis[x])continue;	vis[x]=1;
		rep(i,0,g[x].size()){
			ll to=g[x][i];
			if (d[to]>d[x]+w[x][i]){
				d[to]=d[x]+w[x][i];
				q.push(pa(-d[to],to));
			}
		}
	}
	ll ans=abs(tx-sx)+abs(ty-sy);
	For(i,1,n)ans=min(ans,abs(tx-x[i])+abs(ty-y[i])+d[i]);
	cout<<ans<<endl;
}