/*
 
*/ 
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
const ll N=200010,mod=1e9+7;
char s[N];
ll n;
ll calc(ll x){
	return x*(x+1)/2; 
}
int main(){
	ll T=read();
	for(;T--;){
		scanf("%s",s+1);
		n=strlen(s+1); 
		ll ans=0;
		for(ll i=1,j;i<=n;i=j){
			for(;((s[i]-'0')^(i&1))==1;++i);
			j=i;
			for(;(s[j]=='?')||(((s[j]-'0')^(j&1))==0);++j);
			ans+=calc(j-i);
		}
		for(ll i=1,j;i<=n;i=j){
			for(;((s[i]-'0')^(i&1))==0;++i);
			j=i;
			for(;(s[j]=='?')||(((s[j]-'0')^(j&1))==1);++j);
			ans+=calc(j-i);
		}
		for(ll i=1,j;i<=n;i=j){
			j=i;
			for(;s[j]==s[i];++j);
			if (s[i]=='?')ans-=calc(j-i); 
		}
		cout<<ans<<endl;
	}
}
/*
2
6
*/