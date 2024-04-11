#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define fi first
#define se second
#define cpy(a,b) memcpy(a,b,sizeof (b))
#define pa pair<ll,ll>
#define y1 yyyyyyyyyyyyyyyyy
#define pb push_back
#define mk make_pair
#define debug puts("@@@@@@@@@@@@@@@@@@@@@@@")
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=1001000,mod=1e9+7;
ll n,m,fa[N],sz[N],sz1[N];	char s[100];
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);} 
ll did(){

		For(i,1,2*n)fa[i]=i,sz[i]=sz1[i]=0;
		For(i,1,m){
			ll x=read(),y=read();
			scanf("%s",s+1);
			if (s[1]=='i'){
				fa[find(x)]=find(y+n);
				fa[find(x+n)]=find(y);
			}else{
				fa[find(x)]=find(y);
				fa[find(x+n)]=find(y+n);
			}
		}
		For(i,1,n)if (find(i)==find(i+n))return -1;
		ll ans=0;
		For(i,1,n)sz[find(i)]++;
		For(i,n+1,2*n)sz1[find(i)]++; 
		For(i,1,n)if (find(i)==i)ans+=max(sz[i],sz1[i]);
		return ans; 
}
int main(){
	for(ll T=read();T--;){
		n=read();	m=read();
		cout<<did()<<endl; 
	}
}