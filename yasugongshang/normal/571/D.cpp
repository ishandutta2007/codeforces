#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
const int N=500005;
int n,m,x[N],y[N];
vector<int> v[N];
ll ans[N];
struct d2{
	int tot,fa[N<<1];
	int mx[N<<1];
	void clear(){
		for(int i=1;i<=n+m;i++)fa[i]=i; tot=n;
	}
	inline int gf(int x){
		if(fa[x]==x)return x;
		int f=gf(fa[x]);
		mx[x]=max(mx[fa[x]],mx[x]);
		return fa[x]=f;
	}
	void merge(int x,int y){
		int t1=gf(x),t2=gf(y);
		if(t1==t2)return;
		int k=++tot;
		fa[t1]=k; fa[t2]=k;
	}
	int ask(int x){
		gf(x); return mx[x];
	}
	void add(int x,int y){
		x=gf(x); mx[x]=max(mx[x],y);
	}
}T2;
struct d1{
	int tot,fa[N<<1],sz[N<<1];
	ll mx[N<<1];
	void clear(){
		for(int i=1;i<=n+m;i++)sz[fa[i]=i]=i<=n; tot=n;
	}
	inline int gf(int x){
		if(fa[x]==x)return x;
		int f=gf(fa[x]);
		if(f!=fa[x])mx[x]+=mx[fa[x]];
		return fa[x]=f;
	}
	void merge(int x,int y){
		int t1=gf(x),t2=gf(y);
		if(t1==t2)return;
		int k=++tot;
		fa[t1]=k; fa[t2]=k; sz[k]+=sz[t1]+sz[t2];
	}
	ll ask(int x){
		gf(x); return fa[x]==x?mx[x]:mx[x]+mx[fa[x]];
	}
	void add(int x,int y){
		mx[gf(x)]+=y;
	}
}T1;
char ch[N][3];
int main(){
	n=read(); m=read();
	T1.clear(); T2.clear();
	for(int i=1;i<=m;i++){
		scanf("%s",ch[i]);
		if(ch[i][0]=='U'||ch[i][0]=='M'){
			x[i]=read(); y[i]=read();
		}else{
			x[i]=read();
		}
	}
	for(int i=1;i<=m;i++)if(ch[i][0]=='M'){
		T2.merge(x[i],y[i]);
	}else if(ch[i][0]=='Z'){
		T2.add(x[i],i);
	}else if(ch[i][0]=='Q'){
		v[T2.ask(x[i])].push_back(i); 
	}
	for(int i=1;i<=m;i++){
		if(ch[i][0]=='U'){
			T1.merge(x[i],y[i]);
		}else if(ch[i][0]=='A'){
			T1.add(x[i],T1.sz[T1.gf(x[i])]);
		}else if(ch[i][0]=='Q'){
			ans[i]+=T1.ask(x[i]);
		}
		for(auto j:v[i])ans[j]-=T1.ask(x[j]);
	}
	for(int i=1;i<=m;i++)if(ch[i][0]=='Q')writeln(ans[i]);
}