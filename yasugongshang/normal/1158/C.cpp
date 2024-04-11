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
const int N=500005;
int ans[N],fl;
vector<int> v[N];
void solve(int l,int r,int R){
	if(l>r)return;
	int pos=*lower_bound(v[r+1].begin(),v[r+1].end(),l);
	//cout<<l<<" "<<r<<" "<<pos<<" "<<v[4].size()<<" "<<v[4][0]<<endl;
	if(pos>r){fl=0; return;}
	ans[pos]=R;
	solve(l,pos-1,R-1-(r-pos));
	solve(pos+1,r,R-1);
}
int main(){
	int T=read();
	while(T--){
		fl=1; int n=read();
		For(i,1,n)v[i+1].clear();
		For(i,1,n){
			int a=read(); if(a==-1)a=i+1;
			v[a].pb(i);
		}
		For(i,2,n+1)v[i].pb(n+1);
		solve(1,n,n);
		if(fl){For(i,1,n)wri(ans[i]); puts("");} else puts("-1");
	}
}
/*
1
4
4 -1 4 5

*/