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
const int N=300005;
int p[N],a[N];
vector<PI > ans;
void swp(int x,int y){
	if(x==y)return;
	swap(a[x],a[y]);
	swap(p[a[x]],p[a[y]]);
	ans.pb(mp(x,y));
}
int main(){
	int n=read();
	For(i,1,n)p[a[i]=read()]=i;
	For(i,2,n-1){
		if(p[i]<=n/2){swp(p[i],n); if(i>n/2)swp(p[i],1);}
		else {swp(p[i],1); if(i<=n/2)swp(p[i],n);}
		swp(p[i],i);
	}
	if(a[1]!=1)swp(1,n);
	cout<<ans.size()<<endl;
	for(auto i:ans){
		wri(i.fi); writeln(i.se);
		assert(abs(i.fi-i.se)*2>=n);
	}
	For(i,1,n)assert(a[i]==i);
}