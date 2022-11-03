#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define For(i,x,y) for(ll i =(x);i <= (y);++i)
#define FOr(i,x,y) for(ll i = (x);i >= (y);--i)
#define rep(i,x,y) for(ll i = (x);i < (y);++i)
#define mk make_pair
#define pb push_back
#define y1 y111111111111
#define Debug puts("@@@@@@@@@@@@@@@@")
#define fi first
#define se second
#define clr(a,b) memset(a,b,sizeof a)
#define cpy(a,b) memcpy(a,b,sizeof a)
#define pa pair<ll,ll>
 
inline ll read(){
	ll x = 0,f= 1;char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
void write(ll x){
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) write(x/10);
	putchar('0'+x%10);
}
const ll maxn=400010,maxm=400010;
vector<ll>g[maxn],h[maxn];
ll vis[maxn],dfn[maxn],low[maxn],tim;
ll ncnt,bel[maxn],sum[maxn],f[maxn];
ll cnt,head[maxn],nxt[maxm],to[maxm];
ll sta[maxn],top;
ll n,m,val[maxn],x[maxm],y[maxm],fq[maxn],value[maxn],dep[maxn],ans;
void add(int a,int b,int w)
{
    nxt[++cnt] = head[a];
    to[cnt] = b;
    head[a] = cnt;
    value[cnt]=w;
}
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++tim;
    sta[++top] = x;
    vis[x] = 1;
    for(int i = head[x];i;i = nxt[i])
    {
        int v = to[i];
        if(!dfn[v])
        {
        	dep[v]=dep[x]+value[i];
            tarjan(v);
            low[x] = min(low[x],low[v]);
        }
        else if(vis[v]){
            low[x] = min(low[x],dfn[v]);
            fq[x]=gcd(fq[x],dep[x]-dep[v]+value[i]);
//            cout<<dep[x]<<' '<<dep[v]<<' '<<value[i]<<' '<<endl;
        }
    }
    if(low[x] == dfn[x])
    {
        ncnt++;
        while(sta[top+1] != x)
        {
            bel[sta[top]] = ncnt;
            h[ncnt].pb(sta[top]);
            sum[ncnt] += val[sta[top]];
            vis[sta[top--]] = 0;
        }
    }
}
void dijstra(ll x){
	ll res=0;
	rep(i,0,h[x].size()){
		res=gcd(fq[h[x][i]],res);
	}
        res=abs(res);
	if (res==0)res=1e9+7;
	rep(i,0,h[x].size()){
		fq[h[x][i]]=res;
	}
}
int main(){
	n=read();	m=read();
	For(i,1,m){
		ll a=read(),b=read(),w=read();
		add(a,b,w);
	}
	For(i,1,n)if (!dfn[i])tarjan(i);
//	cout<<ncnt<<endl;
	For(i,1,ncnt)dijstra(i);
//	For(i,1,n)write(fq[i]),putchar(' ');puts("");
	//For(i,1,n)write(bel[i]),putchar(' ');puts("");
	ll q=read();
	for(;q--;){
		ll x=read(),a=read(),p=read();
		if (a==0)puts("YES");
		else if (fq[x]==1e9+7)puts("NO");
		else{
			ll t=gcd(fq[x],p);
			if ((p-a)%t!=0)puts("NO");
			else puts("YES");
		}
	}
}