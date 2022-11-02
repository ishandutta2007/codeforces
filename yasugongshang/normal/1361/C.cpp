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
#define getchar gc
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
const int N=1<<20|2,M=N;
int n,ne,d[N],nxt[M],ed[M],son[N],id[M],q[M],f[M],top;
pair<int,int> a[N];
void ins(int s,int t,int x){
	nxt[++ne]=son[s]; son[s]=ne; ed[ne]=t; 
	d[s]++; id[ne]=x;
}
void dfs(int x){
	for(int i=son[x];i;i=son[x]){
		while(i&&f[abs(id[i])])i=nxt[i];
		son[x]=i;
		if(i){
			f[abs(id[i])]=1;
			dfs(ed[i]);
			q[++top]=id[i];
		}
	}
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read();
	For(i,1,n){
		a[i].fi=read(); a[i].se=read();
	}
	Rep(ans,20,0){
		mem(son); mem(d); ne=top=0;
		mem(f);
		For(i,1,n){
			int s=a[i].fi&((1<<ans)-1),t=a[i].se&((1<<ans)-1);
			ins(s,t,i); ins(t,s,-i);
			//if(ans==3)cout<<s<<" "<<t<<endl;
		}
		int f=1;
		For(i,0,(1<<ans)-1)if(d[i]&1)f=0;
		if(!f)continue;
		For(i,0,(1<<ans)-1)if(d[i]){
			dfs(i); break;
		}
		if(top!=n)continue;
		writeln(ans);
		//For(i,1,top)wri(q[i]); puts("");
		Rep(i,top,1){
			if(q[i]>0){wri(2*q[i]-1); wri(2*q[i]);}
			else{wri(2*(-q[i])); wri(2*(-q[i])-1);}
		}
		return 0;
	}
}