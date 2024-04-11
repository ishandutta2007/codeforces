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
const int N=55;
int n,m,f[N][N],vis[N][N];
char ch[N][N];
void dfs(int x,int y){
	if(vis[x][y]||f[x][y]==0)return; vis[x][y]=1;
	dfs(x,y-1); dfs(x,y+1); dfs(x-1,y); dfs(x+1,y);
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		n=read(),m=read();
		For(i,1,n)scanf("%s",ch[i]+1);
		mem(f); mem(vis);
		For(i,1,n)For(j,1,m)f[i][j]=1;
		For(i,1,n)For(j,1,m)if(ch[i][j]=='#'){
			f[i][j]=0; 
		}else if(ch[i][j]=='B'){
			f[i-1][j]=f[i][j-1]=f[i+1][j]=f[i][j+1]=0;
		}
		dfs(n,m);
		int ans=1;
		For(i,1,n)For(j,1,m)if(ch[i][j]=='G'&&!vis[i][j])ans=0;
		if(ans)puts("Yes"); else puts("No");
	}
}