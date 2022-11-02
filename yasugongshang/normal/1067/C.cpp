#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
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
int main(){
	int n=read(),t=n/2,dq=0;
	for(int i=1;i<=t;i++){cout<<i<<" "<<(t+1)/2<<endl; dq++;}
	for(int i=1;i<=t;i++)if(i!=(t+1)/2){cout<<(t+1)/2<<" "<<i<<endl; dq++;}
	if(n-dq==2){
		cout<<(t+1)/2<<" "<<t+1<<endl<<t+1<<" "<<(t+1)/2<<endl;
	}else if(n-dq==1){
		cout<<(t+1)/2<<" "<<t+1<<endl;
	}
}
/*
00100
00100
11111
00100
00100
111
11
1
1111111111111111
1
1
1
1
x*(n-1.5x)
-1.5x*x+x*n
*/