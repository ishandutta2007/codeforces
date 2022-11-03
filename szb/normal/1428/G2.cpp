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
ll k,f[N];
int main(){
	clr(f,-60);
	f[0]=0;
	k=(read()-1)*3;ll w=1;
	For(tt,0,5){
		ll ff=read(),t=1;
		FOr(i,999999,0){
			For(j,1,9)if (i>=j*w){
				if (j%3==0)	f[i]=max(f[i],f[i-j*w]+j/3*ff);
				else		f[i]=max(f[i],f[i-j*w]);
			}
		}
		ll kk=k;
		for(;t<=kk;t<<=1){
			FOr(i,999999,3*t*w)	f[i]=max(f[i],f[i-3*t*w]+t*ff);
			kk-=t;
		}
		FOr(i,999999,3*kk*w)f[i]=max(f[i],f[i-3*kk*w]+kk*ff);
		w*=10;
	}
	for(ll q=read();q--;)cout<<f[read()]<<endl;
}