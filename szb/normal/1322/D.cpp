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
const ll N=4010;
ll f[N][N],a[N],c[N],v[N],ans,n,m;
int main(){
	memset(f,-60,sizeof f);
	n=read();	m=read();
	For(i,1,n+m)f[i][0]=0;
	FOr(i,n,1)	a[i]=read();
	FOr(i,n,1)	c[i]=read();
	For(i,1,n+m)v[i]=read();
	For(i,1,n){
		FOr(j,n,1)f[a[i]][j]=max(f[a[i]][j],f[a[i]][j-1]+v[a[i]]-c[i]);
		ll w=n;
		for(ll k=a[i]+1;k<=n+m;++k,w=min(n,w/2+3))
			For(j,0,w)f[k][j/2]=max(f[k][j/2],f[k-1][j]+v[k]*(j/2));
	}
	For(i,1,n+m)ans=max(ans,f[i][0]),ans=max(ans,f[i][1]);
	cout<<ans<<endl;
}