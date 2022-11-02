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
const int N=203;
int n,m,mod,fa[N*N],jjl[N*N];
ll a[N][N];
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
char ch[N][N];
inline int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
int zb(int x,int y){
	return x*(m+1)+y;
}
void mer(int a,int b){
	a=gf(a); b=gf(b);
	if(a==b){puts("0"); exit(0);}
	fa[a]=b;
}
void ins(int x,int y){
	a[x][x]++; a[y][y]++;
	a[x][y]--; a[y][x]--;
}
ll solve(int o){
	int tot=0;
	For(i,0,n)For(j,0,m)if(((i+j)&1)==o&&fa[zb(i,j)]==zb(i,j))jjl[zb(i,j)]=++tot;
	if(tot>201)return 0;
	mem(a);
	For(i,1,n)For(j,1,m)if(ch[i][j]=='*'){
		if(((i+j)&1)==o)ins(jjl[gf(zb(i,j))],jjl[gf(zb(i-1,j-1))]);
		else ins(jjl[gf(zb(i-1,j))],jjl[gf(zb(i,j-1))]);
	}
	int hls=1;
	tot--;
	For(i,1,tot){
		For(j,i,tot)if(a[j][i]){
			swap(a[i],a[j]); if(i!=j)hls*=-1; break;
		}
		ll t=ksm(a[i][i],mod-2); hls=hls*a[i][i]%mod;
		For(j,i,tot)a[i][j]=a[i][j]*t%mod;
		For(j,i+1,tot){
			Rep(k,tot,i)a[j][k]=(a[j][k]-a[j][i]*a[i][k])%mod;
		}
	}//cout<<hls<<endl;
	return (hls+mod)%mod;
}
int main(){
	n=read(),m=read(),mod=read();
	For(i,0,n)For(j,0,m)fa[zb(i,j)]=zb(i,j);
	For(i,1,n){
		scanf("%s",ch[i]+1);
		For(j,1,m)if(ch[i][j]=='\\'){
			mer(zb(i,j),zb(i-1,j-1));
		}else if(ch[i][j]=='/'){
			mer(zb(i,j-1),zb(i-1,j));
		}
	}
	cout<<(solve(0)+solve(1))%mod<<endl;
}