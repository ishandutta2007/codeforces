#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
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
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=200005,M=1<<20|2;
int m,n,k;
struct data{
	int sum,ans;
}tr[M];
map<int,int> Ma[N];
multiset<int> s;
data operator +(data a,data b){
	return (data){a.sum+b.sum,max(b.ans,a.ans+b.sum)};
}
void push_up(int nod){
	tr[nod]=tr[nod<<1]+tr[nod<<1|1];
}
void ins(int l,int r,int pos,int de,int nod){
	if(l==r){
		tr[nod].sum+=de; tr[nod].ans=max(tr[nod].sum,0); return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)ins(l,mid,pos,de,nod<<1);
	else ins(mid+1,r,pos,de,nod<<1|1);
	push_up(nod);
}
void build(int l,int r,int nod){
	if(l==r){
		tr[nod].sum=-1; return; 
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	push_up(nod);
}
data ask(int l,int r,int p,int nod){
	if(r<=p)return tr[nod];
	int mid=(l+r)>>1;
	if(p<=mid)return ask(l,mid,p,nod<<1);
	else return ask(l,mid,p,nod<<1)+ask(mid+1,r,p,nod<<1|1);
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read(),k=read(),m=n<<1; int q=read();
	build(1,m,1);
	s.insert(n);
	For(i,1,q){
		int x=read(),y=read(),de=Ma[x][y]?-1:1;
		Ma[x][y]+=de;
		y+=abs(x-k); 
		if(de>0)s.insert(y);
		else s.erase(s.find(y));
		ins(1,m,y,de,1);
		writeln(ask(1,m,*s.rbegin(),1).ans+(*s.rbegin()-n));
	}
}