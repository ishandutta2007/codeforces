#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 2e5;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

int n,q;
int a[N+5],f[N+5];
set<int> S[N+5];

struct node{
	int minn,maxn,fl,fr,sum;
	node(){minn = maxn = fl = fr = sum = 0;}
	node(int _minn,int _maxn,int _fl,int _fr,int _sum){
		minn = _minn,maxn = _maxn,fl = _fl,fr = _fr,sum = _sum;
	}
	In friend node merge(node a,node b,int l,int m,int r){
//cout<<"merge: l="<<l<<" m="<<m<<" r="<<r<<endl;
//if(l == 0 && m == 2 && r == 5)cout<<"sks "<<f[m+1]<<endl;
		node c;
		c.minn = min(a.minn,b.minn);
		c.maxn = max(max(a.maxn,b.maxn),f[m+1]);
		if(a.minn == b.minn){
			c.fl = a.fl;c.fr = b.fr;
			c.sum = a.sum + b.sum - a.fr - b.fl + max(max(a.fr,b.fl),f[m+1]);
		}
		else if(a.minn > b.minn){
			c.fl = max(max(a.maxn,b.fl),f[m+1]);c.fr = b.fr;
			c.sum = b.sum - b.fl + c.fl;
		}
		else{
			c.fr = max(max(b.maxn,a.fr),f[m+1]);c.fl = a.fl;
			c.sum = a.sum - a.fr + c.fr;
		}
		return c;
	}
};

struct SegTree{
	node d[4*N+5];int fminn[4*N+5];
	In void pushup(int u,int l,int m,int r){
		d[u] = merge(d[glc(u)],d[grc(u)],l,m,r);
	}
	In void pushdown(int u){
		if(fminn[u] == 0)return;
		int lc = glc(u),rc = grc(u);
		d[lc].minn += fminn[u];fminn[lc] += fminn[u];
		d[rc].minn += fminn[u];fminn[rc] += fminn[u];
		fminn[u] = 0;
	}
	In void build(int u,int l,int r){
//cout<<"build: u="<<u<<" l="<<l<<" r="<<r<<endl;
		if(l == r){
			d[u] = node(0,0,0,0,0);
			return;
		}
		int m = (l + r) >> 1;
		build(glc(u),l,m);
		build(grc(u),m + 1,r);
		pushup(u,l,m,r);
	}
	In void ud(int u,int l,int r,int ql,int qr,int dx){
//cout<<"ud: u="<<u<<" l="<<l<<" r="<<r<<" ql="<<ql<<" qr="<<qr<<" dx="<<dx<<endl;
		if(l == ql && r == qr){
			d[u].minn += dx;
			fminn[u] += dx;
			return;
		}
		int m = (l + r) >> 1;
		pushdown(u);
		if(qr <= m)ud(glc(u),l,m,ql,qr,dx);
		else if(ql > m)ud(grc(u),m + 1,r,ql,qr,dx);
		else ud(glc(u),l,m,ql,m,dx),ud(grc(u),m + 1,r,m + 1,qr,dx);
		pushup(u,l,m,r);
	}
In void print(int u,int l,int r){
cout<<"print; u="<<u<<" l="<<l<<" r="<<r<<" minn="<<d[u].minn<<" maxn="<<d[u].maxn<<" fl="<<d[u].fl<<" fr="<<d[u].fr<<" sum="<<d[u].sum<<endl;
if(l == r)return;
int m = (l + r) >> 1;
pushdown(u);
print(glc(u),l,m);
print(grc(u),m + 1,r);
}
	In int query(){
		return n - d[1].sum;
	}
}T;

In void insert(int id){
//cout<<"insert: id="<<id<<endl;
	int t = S[id].size(),l,r;
	if(!t)return;
	set<int> :: iterator it = S[id].begin();l = *it;
	it = S[id].end();it--;r = *it;
	f[l] = t;
	if(l < r)T.ud(1,0,n,l,r - 1,1);
	else T.ud(1,0,n,l,r,0);
}
In void remove(int id){
//cout<<"remove: id="<<id<<endl;
	int t = S[id].size(),l,r;
	if(!t)return;
	set<int> :: iterator it = S[id].begin();l = *it;
	it = S[id].end();it--;r = *it;
	f[l] = 0;
	if(l < r)T.ud(1,0,n,l,r - 1,-1);
}
In void solve(int pos,int x){ // a[pos] <- x
	remove(a[pos]);remove(x);
	S[a[pos]].erase(pos);S[x].insert(pos);	
	insert(a[pos]);insert(x);
//cout<<"f[]:"<<endl;
//for(rg int i = 1;i <= n;i++)cout<<f[i]<<" ";cout<<endl;
//T.print(1,0,n);
	a[pos] = x;
	write(T.query()),putchar('\n');
}

int main(){
//	freopen("CF1209G2.in","r",stdin);
//	freopen("CF1209G2.out","w",stdout);
	n = read();q = read();
	for(rg int i = 1;i <= n;i++){
		a[i] = read();
		S[a[i]].insert(i);
	}
	T.build(1,1,n);
	for(rg int i = 1;i <= N;i++)if(S[i].size())insert(i);
//cout<<"f[]:"<<endl;
//for(rg int i = 1;i <= n;i++)cout<<f[i]<<" ";cout<<endl;
	write(T.query()),putchar('\n');
	for(rg int i = 1;i <= q;i++){
		int pos = read(),x = read();
		solve(pos,x);
	}
	return 0;
}