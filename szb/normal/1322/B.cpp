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
const ll N=400010;
char s[N];
ll n,a[N],ans;
int g[40000010];
int main(){
	n=read();
	For(i,1,n)a[i]=read();
	For(w,0,25){
		ll num0=0,num1=0,cur=(1<<w)-1,ls=0,t=(1<<(w-1));
		For(i,1,n)num1+=a[i]>>w&1,g[a[i]%(1<<w)]++;
		if ((num1*(n-num1))&1)ans^=1<<w;
		if (w){
			For(i,1,t-1){
				ls+=g[(1<<w)-i];
				if ((g[i]&1)&&(ls&1))ans^=1<<w;
			}
			if (g[t]&&(g[t]*(g[t]-1)/2&1))ans^=1<<w;
			if ((g[t]&1)&&(ls&1))ans^=1<<w;
			For(i,t+1,cur){
				ls-=g[i];
				if ((g[i]&1)&&(ls&1))ans^=1<<w;
				if (g[i]&&(g[i]*(g[i]-1)/2&1))ans^=1<<w;
			}
		}
		For(i,0,(1<<w))g[i]=0;
	}
	cout<<ans<<endl;
}