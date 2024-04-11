#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
#define ld long double
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
int n,k,ans;
int sg(int x){
	if(x<2)return x;
	if(x==3)return 1;
	if(x&1)return 0;
	else {
		int t1=sg(x/2),t2=sg(x-1);
		if(t1&&t2)return 0;
		else if(t1==1||t2==1)return 2;
		else return 1;
	}
}
int main(){
	n=read(); k=read();
	if(k&1){
		for(int i=1;i<=n;i++)ans^=sg(read());
	}else{
		for(int i=1;i<=n;i++){
			int t=read();
			if(t<=2)ans^=t; else ans^=(t&1)?0:1;
		}
	}
	puts(ans?"Kevin":"Nicky");
}