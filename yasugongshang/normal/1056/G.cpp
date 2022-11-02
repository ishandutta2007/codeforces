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
int n,m,s,flag;
ll t,last;
map<int,int> S;
int go(int s,ll a,ll b){
	for(;a!=b;a--){
		s=s<m?(s+a)%n:(s+n-a%n)%n;
	}
	return s;
}
int main(){
	n=read(); m=read();
	s=read()-1; t=read();
	last=t/n*n;
	s=go(s,t,last); t=last;
	int ti=0;
	while(t){
		s=go(s,t,t-n); t-=n; ti++; 
		if(flag==0&&S.count(s)){
			t=(t/n)%(ti-S[s])*n; flag=1;
		}else if(!flag)S[s]=ti;
	}
	cout<<s+1<<endl;
}