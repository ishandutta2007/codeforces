#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define ld double
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
const int N=2005;
const ld eps=1e-12;
int n,ans;
ld zs[N];
struct data{
	ld x,y;
}a[N];
bool check(ld x,ld y){
	return fabs(x-y)<=eps;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		int A=read(),B=read(),C=read();
		a[i].x=1.0*B*C/(A*A+B*B);
		a[i].y=1.0*A*C/(A*A+B*B);
	}
	for(int i=1;i<=n;i++){
		int sum=0,tot=0;
		for(int j=i+1;j<=n;j++)if(!check(a[j].y,a[i].y)||!check(a[j].x,a[i].x)){
			if(check(a[j].x,a[i].x))zs[++tot]=1e100;
			else zs[++tot]=(ld)(a[j].y-a[i].y)/(a[j].x-a[i].x);
		}else sum++;
		sort(&zs[1],&zs[tot+1]); int dq=1;
		for(int j=1;j<=sum;j++)ans+=n-i-j;
		for(int j=1;j<=tot;j++){while(!check(zs[dq],zs[j]))dq++; ans+=j-dq;}
	}
	cout<<ans<<endl;
}