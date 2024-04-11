#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int N=1005;
int x[N],y[N],cnt[4],n;
vector<int> v[2][2];
void bao(){
	mem(cnt);
	For(i,1,n)cnt[(x[i]&1)*2+(y[i]&1)]++;
	For(i,0,3)if(cnt[i]==n){
		For(j,1,n){
			x[j]=x[j]%2?(x[j]+1)/2:x[j]/2; y[j]=y[j]%2?(y[j]+1)/2:y[j]/2;
		}
		bao(); return;
	}
}
void pr(vector<int> v){
	for(auto i:v)wri(i);
}
void PR(vector<int> v){
	writeln(v.size()); pr(v);
}
int main(){
	n=read();
	For(i,1,n){
		x[i]=read(),y[i]=read();
	}
	bao();
	For(i,1,n)v[x[i]&1][y[i]&1].pb(i);
	int t=v[0][0].size()+v[1][1].size();
	if(t&&t<n){
		writeln(t); pr(v[0][0]); pr(v[1][1]);
	}else{
		if(v[0][0].size()){
			PR(v[0][0]);
		}else{
			PR(v[0][1]);
		}
	}
}
/*
2
100 100
-100 -100

*/