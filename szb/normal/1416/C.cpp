#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const ll N=3e5+100;
ll ind=1,b,n,answ;
ll ans0[33],ans1[33],sum[N*32],c[N*32][2];
void insert(ll v){
	ll x=1;
	FOr(i,31,0){
		ll to=v>>i&1;	++sum[x];
		if (!to)ans0[i]+=sum[c[x][to^1]];
		else	ans1[i]+=sum[c[x][to^1]]; 
		if (!c[x][to])c[x][to]=++ind;
		x=c[x][to];
	}++sum[x];
}
int main(){
	n=read();
	For(i,1,n)insert(read());
	For(i,0,31){
//		cout<<ans0[i]<<' '<<ans1[i]<<endl;
		if (ans0[i]<=ans1[i])answ+=ans0[i];
		else				answ+=ans1[i],b^=1<<i;
	}
	cout<<answ<<' '<<b<<endl; 
}