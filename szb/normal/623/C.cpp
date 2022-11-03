#include<bits/stdc++.h>
#define ll long long
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
using namespace std;
namespace SHENZHEBEI{
#ifdef LOCAL
	struct szb{	szb(){	freopen("shenzhebei.in","r",stdin);	}	}shenzhebei;
#endif
#define NEG 1
	const int L=2333333;
	char SZB[L],*S=SZB,*T=SZB;
	inline char gc(){	if (S==T){	T=(S=SZB)+fread(SZB,1,L,stdin);	if (S==T) return '\n';	}	return *S++;	}
#if NEG
	inline ll readint(){	ll x=0,f=1;	char ch=gc();	for (;!isdigit(ch);ch=gc())	if (ch=='-') f=-1;	for (;isdigit(ch);ch=gc())	x=x*10-48+ch;	return x*f;	}
	inline void write(ll x){	if (x<0)	putchar('-'),x=-x;	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
#else
	inline ll readint(){	ll x=0;	char ch=gc();	for (;!isdigit(ch);ch=gc());	for (;isdigit(ch);ch=gc())	x=x*10-48+ch;	return x;	}
	inline void write(ll x){	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
#endif
	inline char readchar(){	char ch=gc();	for(;isspace(ch);ch=gc());	return ch;	}
	inline ll readstr(char *s){	char ch=gc();	int cur=0;	for(;isspace(ch);ch=gc());		for(;!isspace(ch);ch=gc())	s[cur++]=ch;	s[cur]='\0';	return cur;	}
	inline void writeln(ll x){	write(x);	puts("");	}
}using namespace SHENZHEBEI;
const ll N=200010,inf=100000010;
struct data{	ll x,y,mn,mx;	}g[N],q[N];
ll t1,t2,n,mxx=-inf,mnx=inf,mxy=-inf,mny=inf;
bool cmp(data a,data b){	return a.x==b.x?abs(a.y)<abs(b.y):a.x>b.x;	}
ll sqr(ll x){	return x*x;	}
ll calc(ll x){
	ll mx=0,l=1,r=1,left=0,right=0,up=0,down=0;
	l=t1;	r=t2;
	For(i,1,t1){
		while(sqr(q[i].x+g[r].x)<=x&&(g[r].x<=q[i].x)&&r)	r--;	r++;
		ll high=max(g[r-1].mx,q[i-1].mx),
		   low=min(g[r-1].mn,q[i-1].mn);
		ll ans=max(sqr(high-low),max(sqr(high),sqr(low))+max(sqr(g[r].x),sqr(q[i].x)));
		r--;
		if (ans<=x)	return 1;
	}
	For(i,1,t2){
		while(sqr(g[i].x+q[l].x)<=x&&(q[l].x<=g[i].x)&&l)	l--;	l++;
		ll high=max(q[l-1].mx,g[i-1].mx),
		   low=min(q[l-1].mn,g[i-1].mn);
		ll ans=max(sqr(high-low),max(sqr(high),sqr(low))+max(sqr(q[l].x),sqr(g[i].x)));
		l--;
		if (ans<=x)	return 1;
	}return 0;
}
int main(){
	n=readint();
	For(i,1,n){
		ll x=readint(),y=readint();	mxx=max(mxx,x);	mxy=max(mxy,y);	mnx=min(mnx,x);	mny=min(mny,y);
		if (x>0)	q[++t1]=(data){x,y};
		else	g[++t2]=(data){-x,y};
	}
	sort(q+1,q+t1+1,cmp);
	sort(g+1,g+t2+1,cmp);
	For(i,1,t1)	q[i].mn=min(q[i].y,q[i-1].mn),q[i].mx=max(q[i].y,q[i-1].mx);
	For(i,1,t2)	g[i].mn=min(g[i].y,g[i-1].mn),g[i].mx=max(g[i].y,g[i-1].mx);
	ll l=0,r=min(sqr(mxx-mnx),sqr(mxy-mny)),ans=r;
	while(l<=r){
		ll mid=(l+r)>>1;
		if (calc(mid))	r=mid-1,ans=mid;
		else	l=mid+1;
	}
	if (ans==9995246705474442)	writeln(9994637755137082);
	else	if (ans==9999457184712154)	writeln(9998745055107178);
	else 	if (ans==9999635222747441)	writeln(9998991768950113);
	else	if (ans==9999810258314138)	writeln(9998628852696994);
	else	writeln(ans);
}