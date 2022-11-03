#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define max(x,y)	x<y?y:x
#define min(x,y)	x<y?x:y
typedef complex<double> E;
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=100100;
struct data{	ll x,y;	}p[N];
ll n,top,a,b,c,d,r[N];
bool cmp(data a,data b){	return a.x==b.x?a.y>b.y:a.x<b.x;	}
int main(){
	n=read();
	a=read();	b=read();	c=read();	d=read();
	For(i,1,n){
		ll x=read(),y=read();
		p[i].y=b*y-a*x;
		p[i].x=c*x-y*d; 
		if (p[i].y<=0||p[i].x<=0)	--i,--n;
	}sort(p+1,p+n+1,cmp);
	For(i,1,n)	if (p[i].y>r[top])	r[++top]=p[i].y;
	else	r[lower_bound(r+1,r+top+1,p[i].y)-r]=p[i].y;
	writeln(top);
}