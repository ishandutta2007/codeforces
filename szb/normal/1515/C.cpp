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
const ll N=100010;
ll n,m,x,sum[N],ans[N],id[N];
pa a[N];
priority_queue<pa,vector<pa>,greater<pa> >q;
bool cmp(pa a,pa b){
	return a.fi<b.fi;
}
int main(){
	ll T=read();
	for(;T--;){
		for(;!q.empty();)q.pop();
		n=read();	m=read();	x=read();
		For(i,1,m)sum[i]=0,q.push(mk(sum[i],i));
		For(i,1,n)a[i].fi=read(),a[i].se=i;
		sort(a+1,a+n+1,cmp);
		ll cho=1;
		for(;cho<=n;){
			ll x=q.top().se,y=q.top().fi;q.pop();
			if (y!=sum[x])continue;
			ans[a[cho].se]=x;
			sum[x]+=a[cho++].fi;
			q.push(mk(sum[x],x));
		}
		puts("YES");
		For(i,1,n)write(ans[i]),putchar(' ');puts("");
	}
}
/*
2
5 2 3
1 2 3 1 2
4 3 3
1 1 2 3

*/