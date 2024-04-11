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
const int N=1000005,M=1<<22|2,inf=1e9;
int n,b[N],a[N],sz[M];
PI mn[M],mx[M];
vector<int> v[N];
vector<int> st[N<<1];
void push_up(int nod){
	PI t=mn[nod<<1|1]; t.fi-=sz[nod<<1];
	mn[nod]=min(mn[nod<<1],t);
	t=mx[nod<<1|1]; t.fi-=sz[nod<<1];
	mx[nod]=max(mx[nod<<1],t);
	sz[nod]=sz[nod<<1]+sz[nod<<1|1];
}
void bao(int pos,int nod){//cout<<b[1]<< " "<<pos<<" fjz "<<nod<<endl;
	sz[nod]=st[pos].size();
	if(!sz[nod]){
		mn[nod].fi=inf; mx[nod].fi=-inf;
	return;
	}
	mn[nod].se=mx[nod].se=pos;
	mn[nod].fi=pos-N-st[pos].size();
	mx[nod].fi=pos-N-1;
}
void ins(int l,int r,int pos,int nod){
	if(l==r)return bao(l+N,nod);
	int mid=(l+r)>>1;
	if(pos<=mid)ins(l,mid,pos,nod<<1); else ins(mid+1,r,pos,nod<<1|1);
	push_up(nod);
}
void build(int l,int r,int nod){
	if(l==r)return bao(l+N,nod);
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	push_up(nod);
}
void ins(int pos,int de){
	//cout<<pos<<" zykdel"<<" "<<de<<endl;
	pos+=N; //cout<<pos<<" "<<st[pos].size()<<endl;
	if(de)st[pos].pb(de); else st[pos].pop_back();
	ins(-n,n,pos-N,1);
}
void mer(int x,int y){
	a[x]+=a[y];
	if(x==y)return;
	if(v[x].size()<v[y].size())swap(v[x],v[y]);
	for(auto i:v[y])v[x].pb(i);
}
int main(){
	//freopen("std.in","r",stdin);// freopen("zygay.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		For(i,1,n){
			b[i]=a[i]=read(); v[i].clear(); v[i].pb(i);
			st[a[i]+N].pb(i);
		}
		build(-n,n,1);
		Rep(i,n,2){
			int L=st[mn[1].se].back(),R=st[mx[1].se].back();  //cout<<L<<" "<<R<<" "<<a[L]<<" "<<a[R]<<" "<<mn[1].fi<<" "<<mx[1].fi<<endl;
			if(mn[1].fi!=-i||mx[1].fi!=-1){//cout<<L<<" "<<R<<" "<<a[R]<<" "<<mn[1].fi<<" "<<mx[1].fi<<endl;
				if(mn[1].fi==-i)ins(a[L],0);
				else ins(a[R],0);
			}else{
				ins(a[L],0);
				ins(a[R],0);
				mer(L,R);
				ins(a[L],L);
			}
			
		}
		int rt=st[mn[1].se].back();
		writeln(v[rt].size());
		ll sum=0;
		for(auto i:v[rt]){sum+=b[i]; wri(i);} puts("");
		//cout<<sum<<" "<<b[1]<<endl;
		assert(!sum);
		For(i,-n,n)st[i+N].clear();
	}
}
/*
1
4
-3 1 1 1

*/