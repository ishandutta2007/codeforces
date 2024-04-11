#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
const int N=1<<12|2;
int p[N],q[N],b[N],a[N],sum,to[N];
void fix(int x,int y){
	if((p[x]^q[x])==a[x]&&(p[y]^q[y])==a[y])return;// cout<<(a[x]^q[x])<<endl;
	int t=to[a[x]^q[x]]; swap(p[t],p[x]); swap(to[p[t]],to[p[x]]); swap(q[y],q[t]);
	fix(t,y);// cout<<t<<endl;
}
void opt(int x,int y,int de){
	a[x]^=de; a[y]^=de; fix(x,y);
}
int main(){
	int k=read(),n=1<<k;
	For(i,0,n-1){
		b[i]=read(); sum^=b[i]; p[i]=q[i]=to[i]=i;
	}
	if(sum){puts("Fou"); return 0;}
	puts("Shi");
	For(i,0,n-2){
		opt(i,i+1,b[i]); b[i+1]^=b[i];
	}
	For(i,0,n-1)wri(p[i]); puts(""); For(i,0,n-1)wri(q[i]);
}
/*
2
0 1 2 3

*/