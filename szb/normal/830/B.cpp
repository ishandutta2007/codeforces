#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
#define maxn 400010
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
struct data{
	ll v,p;
}a[maxn];
ll sum[maxn],last,ans,n,c[maxn];
ll get(ll x,ll y){
	return (y+n-x)%n;
}
bool cmp(data a,data b){
	return a.v<b.v;
}
bool cmp1(data a,data b){
	return get(last,a.p)<get(last,b.p);
}
void add(ll x,ll v){
	for(;x<=n;x+=x&-x)	c[x]+=v;
}
ll ask(ll x){
	ll ans=0;
	for(;x;x-=x&-x)	ans+=c[x];
	return ans;
}
ll Q(ll x,ll y){
	return sum[y]-sum[x-1]+ask(y)-ask(x-1);
}
ll calc(ll x,ll y){
	if (x<=y)	return Q(x,y);
	else	return Q(x,n)+Q(1,y);
}
int main(){
	n=read();
	For(i,1,n)	a[i].v=read(),a[i].p=i;
	sort(a+1,a+n+1,cmp);	last=1;
	For(i,1,n)	sum[i]=i;
	for(ll i=1,j;i<=n;i=j+1){
		j=i;
		while(a[j+1].v==a[i].v&&j<n)	++j;
		ll cho=i;
		sort(a+i,a+j+1,cmp1);
		For(k,i,j){
			ans+=calc(last,a[k].p);
			last=a[k].p;
			add(a[k].p,-1);
		}
	}
	writeln(ans);
}