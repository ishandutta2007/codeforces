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
const int N=500005;
int tot,qj,n,mx;
int a[N],ans[N],fa[N],qq[10];
pair<int,int> q[N];
set<int> s;
inline int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
struct heap{
	bitset<N> vis;
	priority_queue<int> q;
	void push(int x){
		if(vis[x])vis[x]=0; else q.push(x);
	}
	void erase(int x){
		vis[x]=1;
	}
	int top(){
		while(vis[q.top()]){
			vis[q.top()]=0; q.pop();
		}
		return q.top();
	}
}Q;
void solve(int x){
	auto L=s.lower_bound(x),R=s.upper_bound(x+1); L--;
	tot=0;
	for(auto i=L;;i++){
		qq[++tot]=*i;
		if(i==R)break;
	}
}
void bao(int l,int r){
	//cout<<l<<" "<<r<<" "<<qj<<endl;
	for(int i=gf(l);i<=r;i=gf(i)){
		ans[i]=qj; fa[i]=i+1;
	}
}
void upderase(int x){
	solve(x);
	For(i,1,tot-1){
		int L=qq[i],R=qq[i+1];
		Q.erase(R-L);
	}
}
void updinsert(int x){
	solve(x);
	For(i,1,tot-1){
		int L=qq[i],R=qq[i+1];
		Q.push(R-L);
		if(a[L]==1&&a[R]==1)bao(L,R);
		else if(a[L]==1)bao(L,(L+R)/2-1);
		else if(a[R]==1)bao((L+R)/2,R);
	}
}
void re(int x){
	upderase(x);
	if(x!=1&&a[x]==a[x-1])s.erase(x);
	if(x!=n&&a[x]==a[x+1])s.erase(x+1);
	a[x]=1; if(x==1)a[0]=1; if(x==n)a[n+1]=1;
	if(x!=1&&a[x]==a[x-1])s.insert(x);
	if(x!=n&&a[x]==a[x+1])s.insert(x+1);
	updinsert(x);
}
int main(){
	n=read(); 
	For(i,1,n)q[i]=mp(read(),i);
	sort(q+1,q+n+1);
	For(i,0,n+3)fa[i]=i;
	For(i,0,n+2){
		s.insert(i); Q.push(1);
	}
	Rep(i,n,1){
		qj=q[i].fi;
		re(q[i].se);
		if(q[i].fi!=q[i-1].fi)mx=max(mx,Q.top());
		//cout<<i<<" fjzzq "<<q[i].se<<" "<<mx<<endl;
	}
	writeln((mx-1)/2);
	For(i,1,n)wri(ans[i]);
}