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
const ll N=500010;
vector<ll>e[N];
ll c[N],u[N],v[N],id[N],n,m;
bool cmp(ll a,ll b){return e[a]<e[b];}
int main(){
	for(ll T=read();T--;){
		n=read();m=read();
		For(i,1,n)c[i]=read(),e[i].clear(),id[i]=i;
		For(i,1,m)u[i]=read(),v[i]=read(),e[v[i]].pb(u[i]);
		For(i,1,n)sort(e[i].begin(),e[i].end());
		sort(id+1,id+n+1,cmp);
		ll sum=0,ans=0;
		For(i,1,n)if (e[id[i]].size()){
			if (e[id[i]]==e[id[i-1]])sum+=c[id[i]];
			else	ans=__gcd(ans,sum),sum=c[id[i]];
		}ans=__gcd(ans,sum);
		write(ans);puts("");
	}
}