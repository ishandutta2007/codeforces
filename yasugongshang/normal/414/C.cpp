#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
#define ld long double
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
const int N=1<<20|3;
ll sum[25],ans[N<<1],Alb[N<<1],Ans[25],ycl[25];
int n,dep[N<<1],a[N],b[N];
void solve(int l,int r,int nod){
	if(l+1==r)return;
	int mid=(l+r)>>1; 
	solve(l,mid,nod<<1); solve(mid,r,nod<<1|1);
	int dq=mid,dd=mid;
	ans[nod]=ans[nod<<1]+ans[nod<<1|1];
	Alb[nod]=Alb[nod<<1]+Alb[nod<<1|1];
	for(int i=l;i<mid;i++){
		while(dq<r&&a[dq]<a[i])dq++;
		while(dd<r&&a[dd]<=a[i])dd++;
		ans[nod]+=dq-mid; Alb[nod]+=dd-dq;
	}
	dep[nod]=dep[nod<<1]+1;
	sum[dep[nod]]+=ans[nod];
	ycl[dep[nod]]-=Alb[nod];
	merge(&a[l],&a[mid],&a[mid],&a[r],&b[l]);
	for(int i=l;i<r;i++)a[i]=b[i];
}
int main(){
	n=read();
	for(int i=0;i<(1<<n);i++)a[i]=read();
	for(int i=0;i<=n;i++){
		ycl[i]=(ll)(1<<n)*((1<<i)-1)/2;
	}
	solve(0,1<<n,1);
	ll jb=sum[n];
	int q=read();// cout<<jb<<" "<<ycl[n]<<" "<<sum[n]<<" "<<Alb[1]<<endl;
	while(q--){
		int t=read(); ll delta=ycl[t]-2*sum[t];
		jb+=delta;
		for(int j=0;j<=t;j++)sum[j]=ycl[j]-sum[j];
		for(int j=t+1;j<=n;j++)sum[j]+=delta;
		writeln(jb);
	}
}