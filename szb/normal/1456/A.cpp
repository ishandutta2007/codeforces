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
const double eps = 1e-7;
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
const ll N=1000100;
ll n,p,k,x,y,a[N],calc[N];
char s[N];
int main(){
	for(ll T=read();T--;){
		n=read();	p=read();	k=read();
		scanf("%s",s+1);
		x=read();	y=read();
		For(i,1,n)a[i]=s[i]-'0';
		For(i,1,n+k)calc[i]=0;
		FOr(i,n,1)calc[i]=calc[i+k]+(1-a[i])*x;
		ll ans=1e18;
		For(i,p,n){
			ans=min(ans,(i-p)*y+calc[i]);
		}
		write(ans);puts("");
	}
}
/*
3
10 3 2
0101010101
2 2
5 4 1
00000
2 10
11 2 3
10110011000
4 3
*/