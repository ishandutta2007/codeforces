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
const int N=100005;
vector<int> v[N],ans,qj;
int fa[N],vis[N],bj[N];
void dfs(int p){
	vis[p]=1;
	for(auto i:v[p])if(i!=fa[p]){
		if(ans.size())return;
		if(vis[i]){
			for(int j=p;j!=fa[i];j=fa[j])ans.pb(j); return;
		}
		fa[i]=p; dfs(i);
	}
	if(!bj[p]){
		bj[fa[p]]=1; qj.pb(p);
	}
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read(),m=read(),k=read();
	while(m--){
		int s=read(),t=read();
		if(s<=k&&t<=k){
			v[s].pb(t); v[t].pb(s);
		}
	}
	For(i,1,n)if(!vis[i]){
		dfs(i);
	}
	if(ans.size()){
		puts("2");
		writeln(ans.size());
		for(auto i:ans)wri(i);
	}else{
		puts("1");
		qj.resize((k+1)/2);
		for(auto i:qj)wri(i);
	}
}