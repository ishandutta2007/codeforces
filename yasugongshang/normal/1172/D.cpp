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
const int N=1005;
vector<pair<PI,PI> > ans;
int tr[N],r[N],c[N],tc[N];
void swax(int x,int y){
	swap(r[x],r[y]);
	swap(tr[r[x]],tr[r[y]]);
}
void sway(int x,int y){
	swap(c[x],c[y]);
	swap(tc[c[x]],tc[c[y]]);
}
int main(){
	int n=read();
	For(i,1,n)tr[r[i]=read()]=i; For(i,1,n)tc[c[i]=read()]=i; //r[i]i
	For(i,1,n){
		if(tr[i]!=i||tc[i]!=i){
			ans.pb(mp(mp(tr[i],i),mp(i,tc[i]))); //[tr[i]][i]=ans[i][tc[i]]=
			swax(tr[i],i);
			sway(tc[i],i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto i:ans){
		wri(i.fi.fi); wri(i.fi.se); wri(i.se.fi); writeln(i.se.se);
	}
}