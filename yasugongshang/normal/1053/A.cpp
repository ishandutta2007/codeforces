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
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=1000005;
ll n,m,k;
signed main(){
	n=read(); m=read(); k=read();
	if(n*m*2%k)puts("NO");
	else{
		ll tt=__gcd(n*2,k);
		k/=tt; 
		puts("YES");
		if(tt>=2)
		cout<<n*2/tt<<" "<<0<<endl<<0<<" "<<m/k<<endl<<0<<" "<<0<<endl;
		else cout<<n/tt<<" "<<0<<endl<<0<<" "<<m*2/k<<endl<<0<<" "<<0<<endl;
	}
}