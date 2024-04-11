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
const int N=50005;
struct da{
	int x,y,z,id;
}a[N];
bool cmp(da a,da b){
	if(a.x==b.x&&a.y==b.y)return a.z<b.z;
	else return a.x==b.x?a.y<b.y:a.x<b.x;
}
int main(){
	int n=read();
	For(i,1,n){
		a[i].x=read(); a[i].y=read(); a[i].z=read(); a[i].id=i;
	}
	sort(&a[1],&a[n+1],cmp);
	int m=0;
	For(i,1,n){
		if(i<n&&a[i].x==a[i+1].x&&a[i].y==a[i+1].y){
			wri(a[i].id); writeln(a[i+1].id); i++;
		}else a[++m]=a[i];
	}
	n=m; m=0;
	For(i,1,n){
		if(i<n&&a[i].x==a[i+1].x){
			wri(a[i].id); writeln(a[i+1].id); i++;
		}else a[++m]=a[i];
	}
	n=m;
	For(i,1,n){
		wri(a[i].id); writeln(a[i+1].id); i++;
	}
}