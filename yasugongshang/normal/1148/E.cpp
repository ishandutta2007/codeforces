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
PI a[N];
int b[N];
int q1[N],q2[N];
vector<pair<PI,int> > ans;
void GG(){
	puts("NO"); exit(0);
}
void bao(int x,int y,int de){
	a[x].fi+=de; a[y].fi-=de; 
	ans.pb(mp(mp(a[x].se,a[y].se),de));
}
int main(){
	int n=read(); ll sum=0;
	For(i,1,n){a[i].fi=read(); a[i].se=i;}
	For(i,1,n){b[i]=read(); }
	sort(&a[1],&a[n+1]);
	sort(&b[1],&b[n+1]);
	sum=0;
	For(i,1,n){sum+=b[i]-a[i].fi; if(sum<0)GG(); if(b[i]>=a[i].fi)q1[++*q1]=i; else q2[++*q2]=i;}
	if(sum)GG();
	int dq=1;
	For(i,1,*q1){
		while(b[q1[i]]!=a[q1[i]].fi){
			int t=min(b[q1[i]]-a[q1[i]].fi,a[q2[dq]].fi-b[q2[dq]]);
			if(!t){dq++; continue;}
			bao(q1[i],q2[dq],t);
		}
	}
	puts("YES");
	cout<<ans.size()<<endl;
	for(auto i:ans){
		wri(i.fi.fi); wri(i.fi.se); writeln(i.se);
	}
}