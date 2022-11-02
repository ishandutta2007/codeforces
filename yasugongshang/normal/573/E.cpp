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
const int N=100005;
ll v[N];
int dq,n;
struct SPLAY{
	int rt,fa[N],ch[N][2],sz[N];
	ll A[N],B[N];
	void print(){
		cout<<"debug"<<endl;
		cout<<rt<<endl;
		For(i,1,dq)cout<<fa[i]<<" "<<ch[i][0]<<" "<<ch[i][1]<<" "<<sz[i]<<endl;
		cout<<"end"<<endl;
	}
	inline int get(int x){return ch[fa[x]][1]==x;}
	inline void update(int x){sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;}
	inline void cao(int x,ll y,ll z){v[x]+=y*(sz[ch[x][0]]+1)+z; A[x]+=y; B[x]+=z;}
	void pushdown(int x){
		cao(ch[x][0],A[x],B[x]);
		cao(ch[x][1],A[x],B[x]+A[x]*(sz[ch[x][0]]+1));
		A[x]=B[x]=0;
	}
	void push(int x){
		if(fa[x])push(fa[x]);
		pushdown(x);
	}
	void rotate(int x){
		int f=fa[x],g=fa[f],c=get(x);
		fa[x]=g; if(g)ch[g][get(f)]=x;
		ch[f][c]=ch[x][c^1]; fa[ch[f][c]]=f;
		ch[x][c^1]=f; fa[f]=x;
		update(f); update(x);
	}
	void splay(int x){
		for(push(x);fa[x];rotate(x))
			if(fa[fa[x]])rotate(get(x)==get(fa[x])?fa[x]:x);
		update(rt=x);
	}
	int ask(int x,int k){
		//cout<<CMP(key[x],k)<<" "<<k<<" "<<X<<" "<<Get(key[x])<<" fjzzq\n";
		//if(x)cout<<x<<" "<<k<<" "<<s[x]<<endl;
		if(k<=sz[ch[x][0]])return ask(ch[x][0],k);
		else if(k>sz[ch[x][0]]+1)return ask(ch[x][1],k-sz[ch[x][0]]-1);
		else {splay(x); return x;}
	}
	void inse(int &x,int y,int fff){
		if(!x){push(fff); x=y; sz[x]=1; fa[x]=fff; splay(x);return;}
		inse(ch[x][0],y,x);
	}
	void ins(int x,int y){inse(ch[x][1],y,x);}
	int ask(int k){return ask(rt,k);}
	void dfs(int p){
		if(!p)return;
		pushdown(p);
		dfs(ch[p][0]);
		dfs(ch[p][1]);
	}
}T;
int main(){
	dq=T.rt=1; n=read();
	For(i,1,n){
		int a=read();
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(v[T.ask(mid+1)]<=v[T.ask(mid)]+(ll)mid*a)r=mid;  else l=mid+1;
		}
		int id=T.ask(l);
		v[++dq]=v[id];
		T.ins(id,dq); T.splay(id);
		T.cao(T.ch[id][1],a,(ll)(l-1)*a);
		//cout<<l<<" wodfa "<<id<<" "<<(l-1)*a<<" "<<a<<endl;
		//T.dfs(1); 
		//For(j,1,i+1)wri(v[T.ask(j)]); puts("");
	}
	T.dfs(T.rt);
	ll ans=0;
	For(i,1,n+1)ans=max(ans,v[i]);
	cout<<ans<<endl;
}