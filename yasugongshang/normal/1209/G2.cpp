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
const int N=200005,M=1<<19|2;
struct data{
	int ans,lm,rm,mn,mx;
}tr[M];
int n,q,lzy[M],a[N];
set<int> s[N];
void push_up(data &c,data a,data b){
	if(a.mn<b.mn){
		c.mn=a.mn;
		c.rm=max(a.rm,b.mx);
		c.lm=a.lm;
		c.ans=a.ans;
	}else if(a.mn>b.mn){
		c.mn=b.mn;
		c.lm=max(b.lm,a.mx);
		c.rm=b.rm;
		c.ans=b.ans;
	}else{
		c.mn=a.mn;
		c.rm=b.rm;
		c.lm=a.lm;
		c.ans=a.ans+b.ans+max(a.rm,b.lm);
	}
	c.mx=max(a.mx,b.mx);
}
void cao(int nod,int x){
	lzy[nod]+=x; tr[nod].mn+=x;
}
void pushdown(int nod){
	if(lzy[nod]){
		cao(nod<<1,lzy[nod]); cao(nod<<1|1,lzy[nod]); lzy[nod]=0;
	}
}
void ins(int l,int r,int i,int j,int de,int nod){
	if(i>j)return;
	if(l==i&&r==j){
		cao(nod,de); return;
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)ins(l,mid,i,j,de,nod<<1);
	else if(i>mid)ins(mid+1,r,i,j,de,nod<<1|1);
	else{ins(l,mid,i,mid,de,nod<<1); ins(mid+1,r,mid+1,j,de,nod<<1|1);}
	push_up(tr[nod],tr[nod<<1],tr[nod<<1|1]);
}
void zyk(int l,int r,int pos,int de,int nod){
	if(l==r){
		tr[nod].ans=tr[nod].mx=de; return;
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(pos<=mid)zyk(l,mid,pos,de,nod<<1); else zyk(mid+1,r,pos,de,nod<<1|1);
	push_up(tr[nod],tr[nod<<1],tr[nod<<1|1]);
	//if(nod==1)cout<<tr[nod].mn<<" "<<tr[nod<<1].rm<<" "<<tr[nod<<1|1].mn<<endl;
}
void del(int x){
	if(s[x].empty())return;
	ins(1,n,*s[x].begin(),*s[x].rbegin()-1,-1,1);
	zyk(1,n,*s[x].begin(),0,1);
}
void add(int x){//puts("fjz");
	if(s[x].empty())return;
	ins(1,n,*s[x].begin(),*s[x].rbegin()-1,1,1);
	zyk(1,n,*s[x].begin(),s[x].size(),1); //puts("fjt");
}

int main(){
	n=read(),q=read();
	For(i,1,n)s[a[i]=read()].insert(i);
	For(i,1,200000)add(i); 
	//cout<<tr[1].ans<<" "<<tr[1].lm<<" "<<tr[1].rm<<endl;
	writeln(n-(tr[1].ans+tr[1].lm+tr[1].rm));
	while(q--){
		int pos=read(),x=read();
		del(a[pos]);
		s[a[pos]].erase(pos);
		add(a[pos]);
		a[pos]=x;
		del(a[pos]); 
		s[a[pos]].insert(pos);
		add(a[pos]);
		writeln(n-(tr[1].ans+tr[1].lm+tr[1].rm));
	}
	
}
/*
5 6
1 1 1 1 3
2 1
4 1
5 3
2 3
4 2
2 1

*/