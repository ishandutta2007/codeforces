#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ld long double
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=1000005;
int n;
int a,b,c,sx,sy,tx,ty;
ld jl(ld sx,ld sy,ld tx,ld ty){
	return sqrt(sqr(tx-sx)+sqr(sy-ty));
}
signed main(){
	cin>>a>>b>>c;
	cin>>sx>>sy>>tx>>ty;
	ld ans=fabs(sx-tx)+fabs(sy-ty);
	if(a==0||b==0)printf("%.10lf\n",(double)ans);
	else{
		ld K=-(ld)a/b,B=-(ld)c/b;
		ld ay=sx*K+B,by=tx*K+B;
		ld ax=(sy-B)/K,bx=(ty-B)/K;
		ans=min(ans,fabs(ay-sy)+fabs(by-ty)+jl(sx,ay,tx,by));
		ans=min(ans,fabs(ax-sx)+fabs(bx-tx)+jl(ax,sy,bx,ty));
		ans=min(ans,fabs(ax-sx)+fabs(by-ty)+jl(ax,sy,tx,by));
		ans=min(ans,fabs(ay-sy)+fabs(bx-tx)+jl(sx,ay,bx,ty));
		printf("%.10lf\n",(double)ans);
	}
}
/*
ax+by+c=0
y=-a/bx-c/b
y=kx+b
*/