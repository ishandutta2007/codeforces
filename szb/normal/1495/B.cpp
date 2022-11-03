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
const ll mod=1e9+7,N=200010;
ll n,mx,sum,ls[N],rs[N],p[N],ans[N],q[N];
int main(){
	n=read();
	For(i,1,n)p[i]=read();
	q[++*q]=1;
//	For(i,2,n-1)cout<<(p[i]-p[i-1])*(p[i+1]-p[i])<<' ';puts("");
	For(i,2,n-1)if ((p[i]-p[i-1])*(p[i+1]-p[i])<0)q[++*q]=i;
	q[++*q]=n;
	For(i,2,*q)mx=max(mx,q[i]-q[i-1]); 
	For(i,2,*q)sum+=q[i]-q[i-1]==mx; 
	if ((mx&1)||(sum!=2))return puts("0"),0; 
	For(i,2,*q-1)if ((q[i+1]-q[i]==mx)&&(q[i]-q[i-1]==mx)&& (p[q[i]]>p[q[i-1]])&&(p[q[i]]>p[q[i+1]])){
			puts("1");
			return 0;
		}
		puts("0");
}