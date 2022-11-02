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
const int N=200005;
#define lowbit(i) i&-i
struct data{
	int a[30],size;
	void insert(int x){
		for(int i=29;x;i--)if(x>>i&1){
			if(a[i])x^=a[i];
			else{a[i]=x; size++; return;}
		}
	}
}T[N<<2];
int n,q,a[N],c[N];
data Merge(data a,data b){
	if(!a.size)return b; if(!b.size)return a;
	for(int i=0;i<30;i++)b.insert(a.a[i]);
	return b;
}
void build(int l,int r,int nod){
	if(l==r){T[nod].insert(a[l]); return;}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	T[nod]=Merge(T[nod<<1],T[nod<<1|1]);
}
inline void change(int pos,int de){
	for(int i=pos;i<N;i+=lowbit(i))c[i]^=de;
}
inline int ask(int pos){
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))ans^=c[i];
	return ans;
}
void insert(int l,int r,int pos,int nod){
	if(l==r){
		T[nod]=T[0]; T[nod].insert(a[l]); return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)insert(l,mid,pos,nod<<1);
	else insert(mid+1,r,pos,nod<<1|1);
	T[nod]=Merge(T[nod<<1],T[nod<<1|1]);
}
data ask(int l,int r,int i,int j,int nod){
	if(i>j)return T[0];
	if(l==i&&r==j)return T[nod];
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1);
	else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1);
	else return Merge(ask(l,mid,i,mid,nod<<1),ask(mid+1,r,mid+1,j,nod<<1|1));
}
void Change(int pos,int de){
	if(pos>n)return; change(pos,de); a[pos]^=de; insert(1,n,pos,1);
}
signed main(){
	n=read(); q=read();
	for(int i=1;i<=n;i++){a[i]=read(); change(i,a[i]^a[i-1]); }
	for(int i=n;i;i--)a[i]=a[i]^a[i-1];
	build(1,n,1);
	for(int i=1;i<=q;i++){
		int op=read(),l=read(),r=read();
		if(op==1){
			int x=read();
			Change(l,x); Change(r+1,x);
		}else{
			data t=ask(1,n,l+1,r,1);
			t.insert(ask(l)); 
			writeln(1<<t.size);
		}
	}
}