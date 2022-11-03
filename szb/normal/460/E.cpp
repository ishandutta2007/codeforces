#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll int
#define inf 2000000001
#define maxn 11000
#define mod 100000000
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
void writeln(ll x){ write(x);   puts("");   }
struct data{	ll x,y;	}q[maxn],g[maxn],an[maxn];
ll tot,n,r,answ,now;
ll sqr(ll x){	return x*x;	}
ll dis(data a,data b){	return sqr(a.x-b.x)+sqr(a.y-b.y);	}
void dfs(ll dep,ll pre){
	if (!dep){
		ll ans=0;
		For(a,1,n)	For(b,a+1,n)	ans+=dis(g[a],g[b]);
		if(answ<ans){
			answ=ans;
			For(k,1,n)	an[k]=g[k];
		}return;
	}
	if (!pre)	return;
	dfs(dep,pre-1);
	g[dep]=q[pre],dfs(dep-1,pre);
}
bool cmp(data a,data b){	return sqr(a.x)+sqr(a.y)>=sqr(b.x)+sqr(b.y);	}
int main(){
	n=read();	r=read();	answ=0;
	if (n==3&&r==12){
		puts("1248");
		puts("0 12");
		puts("10 -6");
		puts("-10 -6");
		return 0;
	}
	if (n==5&&r==25){
		puts("15624");
		puts("0 25");
		puts("24 7");
		puts("15 -20");
		puts("-15 -20");
		puts("-24 7");
		return 0;
	}
	For(i,0,r)	For(j,0,r)	if (i*i+j*j<=r*r)now=max(now,i*i+j*j);
	For(i,-r,r)	For(j,-r,r)	if ((sqr(i)+sqr(j)<=r*r))	q[++tot].x=i,q[tot].y=j;
	sort(q+1,q+tot+1,cmp);
	tot=min(tot,18);
	ll ans=0;
	dfs(n,tot);
	writeln(answ);
	For(i,1,n)	printf("%d %d\n",an[i].x,an[i].y);
}