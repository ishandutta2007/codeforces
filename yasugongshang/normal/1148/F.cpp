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
struct data{
	ll a; int b; bool f;
}a[N];
int bit(ll x){
	return x?(bit(x>>1)^(x&1)):0;
}
ll solve(vector<data> v,int id){
	ll jb=0;
	for(auto i:v){
		if(i.f==0)jb+=i.b;
	}
	if(jb<=0){
		for(auto i:v)if(i.f)jb+=i.b;
		if(jb<0)return 0;
		else return ((ll)1<<(id+1))-1;
	}
	vector<data> zs;
	for(auto i:v)if(i.f==0){
		if(i.a>>id&1)i.f=1; 
		zs.pb(i);
	}
	ll s=solve(zs,id-1); jb=0;
	for(auto i:v)if(i.f){
		if(bit(i.a&s))jb-=i.b; else jb+=i.b;
	}
	if(jb>0)return s^(((ll)1<<(id+1))-1);
	else return s;
}
int main(){
	int n=read();
	ll sum=0;
	For(i,1,n){
		a[i].b=read(); a[i].a=read(); a[i].f=bit(a[i].a); sum+=a[i].b;
	}
	if(sum<0){For(i,1,n)a[i].b*=-1;}
	vector<data> v;
	For(i,1,n)v.pb(a[i]);
	ll ans=solve(v,61);
	cout<<ans<<endl;
}