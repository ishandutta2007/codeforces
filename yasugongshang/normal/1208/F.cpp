#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=1<<20|2,m=21;
int a[N],f[N<<1][2],ans;

int main(){
	int n=read();
	For(i,1,n){
		a[i]=read();
		f[a[i]][1]=f[a[i]][0]; f[a[i]][0]=i;
	}
	For(i,0,m-1)For(j,0,(1<<m)-1)if(j>>i&1){
		if(f[j^(1<<i)][0]>f[j][0]){
			f[j^(1<<i)][1]=max(f[j^(1<<i)][1],f[j][0]);
		}else{
			f[j^(1<<i)][1]=f[j^(1<<i)][0];
			f[j^(1<<i)][0]=f[j][0];
			f[j^(1<<i)][1]=max(f[j^(1<<i)][1],f[j][1]);
		}
	}
	For(i,1,n-2){
		int dq=0;
		Rep(j,m-1,0)if((a[i]>>j&1)==0){
			if(f[dq|(1<<j)][1]>i)dq|=1<<j;
		}
		ans=max(ans,a[i]|dq);
	}
	writeln(ans);
}