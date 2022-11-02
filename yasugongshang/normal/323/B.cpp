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
const int N=1005;
int n;
bitset<N> e[N];
inline int c(int a,int b){
	return a+b>6?a+b-6:a+b;
}
void zeng(int l,int r){
	for(int i=l;i<=r;i+=2){
		for(int j=1;j<i;j++)e[i][j]=e[j][i+1]=1;
		e[i+1][i]=1;
	}
}
signed main(){
	n=read();
	if(n==4){puts("-1"); return 0;}
	if(n%2==1){
		e[1][2]=e[2][3]=e[3][1]=1;
		zeng(4,n);
	}else{
		for(int i=1;i<=6;i++){
			e[i][c(i,1)]=1;
			if(i&1)e[i][c(i,3)]=e[i][c(i,2)]=1; else e[i][c(i,4)]=1;
		}
		zeng(7,n);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			wri(e[i][j]);
		}
		puts("");
	}
}