#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005;
int a[N],b[N],n,m;
bool check(long double x){
	for(int i=1;i<=n;i++){
		x-=(x+m)/a[i];
		if(x<0)return 0;
		x-=(x+m)/b[i];
		if(x<0)return 0;
	}
	return 1;
}
signed main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	double l=0,r=1e9+1;
	if(!check(r)){puts("-1"); return 0;}
	for(int i=1;i<=100;i++){
		double mid=(l+r)/2;
		if(check(mid))r=mid; else l=mid;
	}
	printf("%.10lf\n",l);
}