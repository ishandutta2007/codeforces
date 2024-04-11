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
const int N=300005;
int n,m,flag,dq,sz[N],pos[N],c[N],a[N],b[N],fa[N],rk[N],ans[N];
struct data{
	int id,fa,rk,add,sz;
}q[N<<1];
PI Q[N];
void clear(int x){
	while(dq>x){
		fa[q[dq].id]=q[dq].fa; rk[q[dq].id]=q[dq].rk; sz[q[dq].id]=q[dq].sz; flag+=q[dq].add; dq--;
	}
}
inline int gf(int x){
	return fa[x]==x?x:gf(fa[x]);
}
void Merge(int a,int b){
	int t1=gf(a),t2=gf(b);
	if(t1!=t2){
		if(rk[t1]>rk[t2])swap(t1,t2);
		dq++;
		if((sz[t1]&1)&&(sz[t2]&1)){flag-=2; q[dq].add=2;} else q[dq].add=0;
		q[dq].id=t2; q[dq].fa=fa[t2]; q[dq].rk=rk[t2]; q[dq].sz=sz[t2];
		q[++dq].id=t1; q[dq].fa=fa[t1]; q[dq].rk=rk[t1]; q[dq].sz=sz[t1];
		fa[t1]=t2; sz[t2]^=sz[t1]; if(rk[t1]==rk[t2])rk[t2]++; 
	}
}
void solve(int l,int r,int L,int R){
	if(l>r)return; //cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if(L==R){
		for(int i=l;i<=r;i++)ans[i]=L; return;
	}
	int mid=(l+r)>>1,t1=dq;
	for(int i=l;i<=mid;i++)if(c[i]<L)Merge(a[i],b[i]);
	int t2=dq;
	for(int i=L;i<R;i++)if(pos[i]<=mid){Merge(a[pos[i]],b[pos[i]]); if(flag==0){ans[mid]=i; break;}}
	if(flag)ans[mid]=R;
	clear(t2);
	solve(mid+1,r,L,ans[mid]);
	clear(t1);
	for(int i=L;i<ans[mid];i++)if(pos[i]<l)Merge(a[pos[i]],b[pos[i]]);
	solve(l,mid-1,ans[mid],R);
	clear(t1);
}
signed main(){
	flag=n=read(); m=read();
	for(int i=1;i<=m;i++){
		a[i]=read(); b[i]=read(); Q[i]=mp(c[i]=read(),i); 
	}
	for(int i=1;i<=n;i++){fa[i]=i; sz[i]=1;}
	sort(&Q[1],&Q[m+1]);
	for(int i=1;i<=m;i++)c[pos[i]=Q[i].second]=i;
	solve(1,m,1,m+1);
	Q[m+1].first=-1;
	for(int i=1;i<=m;i++)writeln(Q[ans[i]].first);
}