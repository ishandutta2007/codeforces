#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
#define ld long double
ll n;
ll x[5],y[5];
int main(){
	cin>>n;
	x[0]=y[0]=1; x[1]=y[1]=x[2]=y[2]=n;
	while(1){
		x[3]=(x[0]+x[1])>>1; y[3]=(y[0]+y[2])>>1;
		ld s=(ld)(y[1]-y[0]+1)*(x[2]-x[0]+1)-(ld)(x[2]-x[1])*(y[1]-y[2]);
		//out<<s<<endl;
		if((ld)(x[2]-x[1])*(y[2]-y[0])*2>s){
			x[4]=x[1]; y[4]=y[3];
		}else if((ld)(x[1]-x[0])*(y[1]-y[2])*2>s){
			x[4]=x[3]; y[4]=y[2];
		}else{
			x[4]=x[3]; y[4]=y[3];
		}
		cout<<x[4]<<" "<<y[4]<<endl;
		int t=read();
		if(t==0)return 0;
		if(t==1)x[0]=x[4]+1;
		else if(t==2)y[0]=y[4]+1;
		else {
			y[2]=y[4]-1; x[1]=x[4]-1;
		}
		if(y[2]<y[0]){
			x[2]=x[1]; y[2]=y[1];
		}
		if(x[1]<x[0]){
			x[1]=x[2]; y[1]=y[2];
		}
		//cout<<x[0]<<" "<<y[0]<<" "<<x[1]<<" "<<y[1]<<" "<<x[2]<<" "<<y[2]<<endl;
	}
}