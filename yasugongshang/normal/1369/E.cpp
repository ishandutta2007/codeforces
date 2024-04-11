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
const int N=100005,M=400005,mod=1e9+7;
int ne=1,vis[N<<1],son[N],w[N],d[N],nxt[M],ed[M];
void ae(int a,int b){
	nxt[++ne]=son[a]; son[a]=ne; ed[ne]=b; d[a]++;
} 
queue<int> q;
vector<int> ans;
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read(),m=read();
	For(i,1,n)w[i]=read();
	For(i,1,m){
		int s=read(),t=read();
		ae(s,t); ae(t,s);
	}
	For(i,1,n)if(w[i]>=d[i])q.push(i);
	while(q.size()){
		int t=q.front(); q.pop(); //cout<<t<<endl;
		for(int i=son[t];i;i=nxt[i]){
			if(!vis[i/2]){
				vis[i/2]=1; ans.pb(i/2);
			}
			if(w[ed[i]]==--d[ed[i]]){
				q.push(ed[i]); 
			}	
		}
	}
	if(ans.size()<m)puts("DEAD");
	else {
		puts("ALIVE");
		reverse(ans.begin(),ans.end());
		for(auto i:ans)wri(i);
	}
}