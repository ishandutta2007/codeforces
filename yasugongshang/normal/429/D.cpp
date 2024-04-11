#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((ll)(x)*(x))
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
const int N=100005;
int n;
map<ll,int> M;
ll a[N],ans=4e18;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+read();
	}
	M[a[1]]=1;
	for(int i=2;i<=n;i++){
		auto zs=M.lower_bound(a[i]),it=zs;
		for(int j=0;j<=500&&it!=M.end();j++){
			ans=min(ans,sqr(it->first-a[i])+sqr(it->second-i)); it++;
		}
		it=zs;
		for(int j=0;j<=500&&it!=M.begin();j++){
			it--; ans=min(ans,sqr(it->first-a[i])+sqr(it->second-i));
		}
		M[a[i]]=max(M[a[i]],i);
	}
	writeln(ans);
}