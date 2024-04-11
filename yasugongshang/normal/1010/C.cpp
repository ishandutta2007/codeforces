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
int t,n,p,a[N],vis[N],ans;
signed main(){
	n=read(); p=read();
	for(int i=1;i<=n;i++){
		a[i]=read()%p;
		t=__gcd(t,a[i]);
	}
	for(int i=0;!vis[i];i=(i+t)%p){
		vis[i]=1; ans++;
	}
	writeln(ans);
	for(int i=0;i<p;i++)if(vis[i]){write(i); putchar(' ');}
}