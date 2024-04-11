#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=1<<21|3;
int n,bit[N];
ll a[N],b[N];
char A[N],B[N];
signed main(){
	n=read();
	scanf("%s%s",A,B);
	for(int i=0;i<(1<<n);i++){
		if(i)bit[i]=bit[i>>1]+(i&1);
		a[i]=A[i]-'0'; b[i]=B[i]-'0'; a[i]<<=2*bit[i]; b[i]<<=2*bit[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++)if(j>>i&1){a[j]+=a[j^(1<<i)]; b[j]+=b[j^(1<<i)];}
	}
	for(int i=0;i<(1<<n);i++)a[i]*=b[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++)if(j>>i&1)a[j]-=a[j^(1<<i)];
	}
	for(int i=0;i<(1<<n);i++)putchar((a[i]>>bit[i]>>bit[i]&3)+'0');
}