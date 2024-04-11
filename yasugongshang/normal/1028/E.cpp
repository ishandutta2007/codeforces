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
const int N=150005;
int n,t;
ll mx,a[N],b[N];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)mx=max(mx,a[i]=read());
	for(int i=1;i<=n;i++)if(mx==a[i])t++; a[n+1]=a[1]; a[0]=a[n];
	if(t==n){
		if(a[1]==0){
			puts("YES");
			for(int i=1;i<=n;i++){
				putchar('1'); putchar(' ');
			}
			return 0;
		}
		puts("NO");
		return 0;
	}else{
		for(int i=1;i<=n;i++)if(a[i-1]!=a[i]&&a[i]==mx){
			b[i]=a[i];
			for(int j=i-1;j;j--){b[j]=b[j+1]+a[j]; if(b[j]==b[i])b[j]+=b[i];}
			if(i==n){break;}
			b[n]=b[1]+a[n]; if(i==1)b[n]+=b[i];
			for(int j=n-1;j>i;j--)b[j]=b[j+1]+a[j];
			break;
		}
		puts("YES");
		for(int i=1;i<=n;i++){
			write(b[i]); putchar(' ');
		}
	}
}
/*
a[n-1]
*/