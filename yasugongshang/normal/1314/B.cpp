#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
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
const int M=1<<18|2,inf=1e9;
int a[1<<17|2],ans;
int f[M],g[M];
int build(int l,int r,int nod){
	if(l==r)return a[l];
	int mid=(l+r)>>1;
	int s=build(l,mid,nod<<1)+build(mid+1,r,nod<<1|1);
	if(!s){
		f[nod]=-inf; g[nod]=0; return s;
	}
	if(r-l==1){
		f[nod]=1;
		g[nod]=1;
	}
	else{
		f[nod]=max(f[nod<<1]+g[nod<<1|1]+1,f[nod<<1|1]+g[nod<<1]+1)+(s>=2)*2;
		g[nod]=max(g[nod<<1]+g[nod<<1|1]+2,f[nod]);
	}
	return s;
}
int main(){
	int n=read(),k=read();
	For(i,1,k)a[read()]=1;
	build(1,1<<n,1);
	cout<<g[1]+(k>=1)<<endl;
}