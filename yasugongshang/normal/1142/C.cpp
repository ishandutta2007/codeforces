#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define PI pair<ll,ll>
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
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=100005;
PI a[N],q[N];
int top;
int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		a[i].fi=read(); a[i].se=read(); a[i].se-=a[i].fi*a[i].fi;
	}
	sort(&a[1],&a[n+1]);
	for(int i=1;i<=n;i++){
		while(top>=2&&(q[top].se-q[top-1].se)*(a[i].fi-q[top].fi)<=(a[i].se-q[top].se)*(q[top].fi-q[top-1].fi))top--;
		while(top>=1&&a[i].fi==q[top].fi)top--;
		q[++top]=a[i];
	}
	cout<<top-1<<endl;
}