#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (x);i <= (y);++i)
#define FOr(i,x,y) for(ll i = (x);i >= (y);--i)
#define rep(i,x,y) for(ll i = (x);i < (y);++i)
#define fi first
#define se second
#define pa pair<ll,ll>
#define mk make_pair
#define pb push_back
#define clr(a,b) memset(a,b,sizeof(a))
#define cpy(a,b) memcpy(a,b,sizeof(b))
#define y1 y11111111111111111111
#define debug puts("@@@@@@@@@@@@@@@@@@@@")
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
void write(ll x){
	if (x<0)	putchar('-'),write(-x);
	else{
		if (x>=10)	write(x/10);
		putchar(x%10+'0');
	}
}
const ll N=5000100;
ll d,n,m,k,lcm,a[N],b[N],q[N],u[N],v[N];
void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(b==0){
        d=a;
        x=1,y=0;
    }
    else{
        exgcd(b,a%b,d,y,x);
        y-=(a/b)*x;
    }
}
ll calc(ll a,ll b,ll n,ll m){
	ll d,y,x=0;
	exgcd(n,m,d,d,y);
	x=(x+y*m*a)%(n*m);
	exgcd(m,n,d,d,y);
	x=(x+y*n*b)%(n*m);
	return (x%(n*m)+(n*m))%(n*m);
}
ll check(ll v){
	ll ans=0;
	For(i,1,*q){
		if ((v-q[i]+lcm)/lcm>=0)
			ans+=(v-q[i]+lcm)/lcm;
	}
	ans=v-ans;
	return ans;
}
int main(){
	n=read();	m=read();	k=read();	lcm=n*m/__gcd(n,m);	d=__gcd(n,m);
	For(i,1,n)a[i]=read(),u[a[i]]=i;
	For(i,1,m)b[i]=read(),v[b[i]]=i;
	ll uu=2*max(n,m);
	n/=d;	m/=d;
	For(i,1,uu)if(u[i]&&v[i]){
		ll a=u[i],b=v[i],remain=a%d==0?d:a%d;
//		cout<<a<<' '<<b<<' '<<d<<endl;
		if (a%d!=b%d)continue;

		a=(a/d)+(a%d>0);
		b=(b/d)+(b%d>0);
		ll tim=(calc(a,b,n,m)+(n*m)-1)%(n*m)*d+remain;
		q[++*q]=tim;
	}
//	For(i,1,(*q))cout<<q[i]<<' ';puts("");
	ll l=0,r=2e18;
	for(;l<r;){
		ll mid=(l+r)>>1;
		if (check(mid)>=k)r=mid;
		else	l=mid+1;
	}
	write(r);
}
/*
4 2 4
4 2 3 1
2 1

*/