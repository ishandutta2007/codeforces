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
const ll N=402000;
priority_queue<ll>q;
ll n,w[N],deg[N],answ[N];
int main(){
	ll T=read();
	for(;T--;){
		n=read();
		For(i,1,n)w[i]=read(),deg[i]=0;
		For(i,2,n){
			ll x=read(),y=read();
			++deg[x];++deg[y];
		}
		ll ans=0,pos=n-1;
		For(i,1,n)ans+=deg[i]*w[i];
		For(i,1,n)For(j,1,deg[i]-1)q.push(-w[i]);
		while(!q.empty()){
			answ[pos]=ans;	--pos;
			ans+=q.top();q.pop();
		}answ[1]=ans;
		For(i,1,n-1)cout<<answ[i]<<' ';puts("");
	}
}