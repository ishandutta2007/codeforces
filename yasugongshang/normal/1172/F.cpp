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
#define uint unsigned
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
string an;
#define getchar gc
#define putchar(x) an+=x
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
inline void writeln(ll a){write(a); putchar('\n');}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=1000005,M=1<<21|2;
const ll inf=1e18;
ll sum[M],p;
vector<ll> v[M];
int a[N];
void push_up(int nod){
	sum[nod]=sum[nod<<1]+sum[nod<<1|1];
	int sz=v[nod<<1].size()-1;
	v[nod].resize(v[nod<<1].size()+v[nod<<1|1].size()-1);
	uint dq=1;
	For(i,0,sz){
		ll r=i==sz?inf:v[nod<<1][i+1],jb=sum[nod<<1]-i*p;
		r+=jb; 
		dq--; while(dq<v[nod<<1|1].size()&&v[nod<<1|1][dq]<r){ v[nod][i+dq]=max(v[nod<<1][i],v[nod<<1|1][dq]-jb); dq++;}
	}
	v[nod][0]=-inf;
}
void build(int l,int r,int nod){
	if(l==r){v[nod].resize(2); v[nod][0]=-inf; v[nod][1]=p-a[l]; sum[nod]=a[l]; return;}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	push_up(nod);
}
ll ask(int l,int r,int i,int j,ll x,int nod){
	if(l==i&&r==j){
		return x+sum[nod]-(upper_bound(v[nod].begin(),v[nod].end(),x)-v[nod].begin()-1)*p;
	}
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,x,nod<<1);
	else if(i>mid)return ask(mid+1,r,i,j,x,nod<<1|1);
	else {
		return ask(mid+1,r,mid+1,j,ask(l,mid,i,mid,x,nod<<1),nod<<1|1);
	}
}
int main(){
	int n=read(),m=read(); p=read();
	For(i,1,n)a[i]=read();
	build(1,n,1);
	while(m--){
		int l=read(),r=read();
		writeln(ask(1,n,l,r,0,1));
	}
	cout<<an;
}