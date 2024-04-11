#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
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
const int N=200005;
int SUM,rt,dq,sz[N],mx[N],ne,nxt[N<<1],son[N],ed[N<<1],di[N<<1],w[N];
bool vis[N];
ld sum,sumd,s[N];
void ae(int a,int b,int c){
	nxt[++ne]=son[a]; son[a]=ne; ed[ne]=b; di[ne]=c;
}
void get(int p,int fa){
	sz[p]=1; mx[p]=0;
	for(int i=son[p];i;i=nxt[i])if(ed[i]!=fa&&!vis[ed[i]]){
		get(ed[i],p);
		sz[p]+=sz[ed[i]]; mx[p]=max(mx[p],sz[ed[i]]);
	}  
	mx[p]=max(mx[p],SUM-sz[p]);
	if(mx[p]<mx[rt])rt=p;
}
void lu(int p,int fa,int dep){
	//cout<<rt<<" "<<p<<" "<<dep<<" "<<w[p]<<endl;
	sum+=pow(dep,1.5)*w[p]; ld ds=sqrt(dep)*w[p]*1.5; sumd+=ds; s[dq]+=2*ds;
	//if(rt==3&&p==4)cout<<dep<<" "<<w[p]<<" "<<ds<<endl;
	for(int i=son[p];i;i=nxt[i])if(ed[i]!=fa)lu(ed[i],p,dep+di[i]);
}
pair<ld,int> ans=mp(1e100,0);
void solve(int p){//cout<<p<<endl; if(vis[p])exit(0);
	vis[p]=1; sum=sumd=0; 
	for(int i=son[p];i;i=nxt[i])s[ed[i]]=0;
	for(int i=son[p];i;i=nxt[i]){
		dq=ed[i]; lu(ed[i],p,di[i]);
	}//if(p==3)cout<<p<<" "<<sumd<<" "<<s[4]<<endl;
	ans=min(ans,mp(sum,p));
	for(int i=son[p];i;i=nxt[i])if(sumd-s[ed[i]]<0&&!vis[ed[i]]){
		SUM=sz[ed[i]]; rt=0;
		get(ed[i],0);
		solve(rt);
	}
}
int main(){
	int n=read();
	For(i,1,n)w[i]=read();
	For(i,1,n-1){
		int s=read(),t=read(),c=read();
		ae(s,t,c); ae(t,s,c);
	}
	SUM=n; mx[0]=1e9;
	get(1,0);
	solve(rt);
	wri(ans.se); printf("%.10f\n",(double)ans.fi);
}