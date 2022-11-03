
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
const ll N=1000010;
vector<ll>g[N];
vector<pa>ans;
ll sum,n,a[N],vis[N];
void dfs(ll x){
	if(vis[x])return;
	g[sum].pb(x);
	vis[x]=sum;
	dfs(a[x]);
}
void merge(ll u,ll v){
	ll n1=g[u].size(),n2=g[v].size(),ab,ba;
	u=g[u][0];v=g[v][0];
	ab=u;ba=v;
	ans.pb(mk(u,v));
	swap(a[u],a[v]);
	For(i,1,n2-1){
		ans.pb(mk(u,a[u]));
		ll to=a[u];
		swap(a[u],a[a[u]]);
	}
	For(i,1,n1-1){
		ans.pb(mk(v,a[v]));
		ll to=a[v];
		swap(a[v],a[a[v]]);
	}
	swap(a[ab],a[ba]);
	ans.pb(mk(ab,ba));
}
void work1(ll u){
	ll n=g[u].size(),x,y,z;
	u=g[u][0];	x=u;	y=a[u];
	ans.pb(mk(u,a[u]));
	swap(a[u],a[a[u]]);
	For(i,1,n-3){
		ans.pb(mk(u,a[u]));
		swap(a[u],a[a[u]]);
	}z=a[u];
//	For(i,1,n)cout<<a[i]<<' ';puts("");
	swap(a[y],a[z]);
	ans.pb(mk(y,z));
	swap(a[x],a[z]);
	ans.pb(mk(x,z));
	swap(a[x],a[y]);
	ans.pb(mk(x,y));
}
void work2(){
	for(ll i=1;i<sum;i+=2){
		merge(i,i+1);
	}
}
int main(){
	n=read();
	For(i,1,n)a[i]=read();
	For(i,1,n)if(!vis[i]){
		if(a[i]==i)continue;
		++sum,dfs(i);
	}
	if(sum==0){
	}else if (sum==1){
		For(i,1,n)if (a[i]==i){
			++sum;
			g[sum].pb(i);
			break;
		}
		if(sum==2)work2();
		else work1(1);
	}else if (sum%2==0)work2();
	else{
		for(ll i=1;i<sum;i+=2){
			merge(i,i+1);
		}
		For(i,1,n)if(a[i]==i){
			++sum;
			g[sum].pb(i);
			break;
		}
		merge(sum-1,sum);
	}
	cout<<ans.size()<<endl;
	rep(i,0,ans.size())write(ans[i].fi),putchar(' '),write(ans[i].se),puts("");
}