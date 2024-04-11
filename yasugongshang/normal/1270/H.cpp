#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define pi pair<int,vector<int> >
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
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
const int M=1000005,MM=1<<21|2,N=500005;
int lzy[MM],a[N];
PI tr[MM];
void push_up(int nod){
	tr[nod]=tr[nod<<1].fi==tr[nod<<1|1].fi?mp(tr[nod<<1].fi,tr[nod<<1].se+tr[nod<<1|1].se)
	:min(tr[nod<<1],tr[nod<<1|1]);
	tr[nod].fi+=lzy[nod];
}
void ins(int l,int r,int i,int j,int de,int nod){//cout<<nod<<" "<<i<<" "<<j<<endl;
	if(i<=l&&r<=j){
		lzy[nod]+=de; tr[nod].fi+=de; return;
	}
	int mid=(l+r)>>1;
	if(i<=mid)ins(l,mid,i,j,de,nod<<1); 
	if(j>mid)ins(mid+1,r,i,j,de,nod<<1|1);
	push_up(nod);
}
void ins(int ps,int de){
	//(a[ps]>a[ps+1])cout<<a[ps+1]<<" "<<a[ps]-1<<" "<<de<<endl;
	if(a[ps]>a[ps+1])ins(0,M-1,a[ps+1],a[ps]-1,de,1);
}
void INS(int ps,int de){
	//cout<<a[ps]<<" "<<a[ps]<<" "<<de*5<<endl;
	de*=2; ins(0,M-1,a[ps],a[ps],de,1);
}
void build(int l,int r,int nod){
	tr[nod].se=r-l+1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
}
int main(){
	int n=read(),q=read();
	a[0]=M-1; a[n+1]=0;
	For(i,1,n)a[i]=read(); 
	build(0,M-1,1); 
	For(i,0,n){ins(i,1); INS(i+1,-1);}
	//writeln(tr[1].se);
	For(i,1,q){
		int ps=read(),x=read();
		ins(ps-1,-1); ins(ps,-1);
		INS(ps,1);
		a[ps]=x;
		ins(ps-1,1); ins(ps,1);
		INS(ps,-1);
		writeln(tr[1].se-1);
	}
}
/*
5 0
25 40 30 20 10
1 25
3 45
1 48

*/