#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
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
int q,last;
map<int,int> fa,v;
inline int gf(int x){
	if(!fa.count(x))return x;
	int f=gf(fa[x]);
	v[x]^=v[fa[x]];
	return fa[x]=f;
}
int main(){
	q=read();
	while(q--){
		int op=read();
		if(op==1){
			int l=read()^last,r=read()^last,x=read()^last;
			if(l>r)swap(l,r);
			r++; 
			int tl=gf(l),tr=gf(r);
			if(tl==tr)continue;
			fa[tl]=tr;
			v[tl]=v[l]^v[r]^x;
		}else{
			int l=read()^last,r=read()^last;
			if(l>r)swap(l,r);
			r++;
			int tl=gf(l),tr=gf(r); //cout<<tl<<" wzp "<<tr<<" "<<v[tl]<<" "<<v[tr]<<endl;
			if(tl==tr){
				writeln(last=v[l]^v[r]);
			}else {last=1; puts("-1");}
		}
	}
}