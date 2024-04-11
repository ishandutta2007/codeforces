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
const int N=2005;
int x[N],y[N],n;
bool vis[N];
char ch[N];
ll cha(int xa,int ya,int xb,int yb){
	return (ll)xa*yb-(ll)ya*xb;
}
ll cha(int a,int b,int c){
	return cha(x[b]-x[a],y[b]-y[a],x[c]-x[a],y[c]-y[a]);
}
int pre(int x){
	int ans=0;
	For(i,1,n)if(!vis[i]){
		if(!ans||cha(x,ans,i)>0)ans=i;
	}
	return ans;
}
int nxt(int x){
	int ans=0;
	For(i,1,n)if(!vis[i]){
		if(!ans||cha(x,ans,i)<0)ans=i;
	}
	return ans;
}
int main(){
	n=read(); int pos=0;;
	For(i,1,n){
		x[i]=read(); y[i]=read();
		if(!pos||x[pos]>x[i])pos=i;
	}
	scanf("%s",ch+1);
	wri(pos); vis[pos]=1;
	For(i,1,n-2){
		if(ch[i]=='R')pos=pre(pos);
		else pos=nxt(pos);
		vis[pos]=1;
		wri(pos);
	}
	For(i,1,n)if(!vis[i])writeln(i);
}