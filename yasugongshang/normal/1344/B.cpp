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
const int N=1005;
int n,m,ans,fa[N*N],f[N],g[N];
char ch[N][N];
inline int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
void mer(int a,int b){
	a=gf(a); b=gf(b);
	fa[a]=b;
}
inline int zb(int x,int y){
	return (x-1)*m+y;
}
int main(){
	n=read(),m=read();
	For(i,1,n){
		scanf("%s",ch[i]+1);
	}
	For(i,1,n*m)fa[i]=i;
	For(i,1,n){
		For(j,1,m){
			if(ch[i][j]=='#'){
				if(ch[i-1][j]=='#')mer(zb(i,j),zb(i-1,j));
				if(ch[i][j-1]=='#')mer(zb(i,j),zb(i,j-1));
			f[i]=1; g[j]=1;
			}
		}
	}
	For(i,1,n*m)if(fa[i]==i&&ch[(i+m-1)/m][i%m?i%m:m]=='#')ans++;
	int ff=0,gg=0;
	For(i,1,n)if(!f[i])ff=1;
	For(j,1,m)if(!g[j])gg=1;
	if(ff+gg==1)ans=-1;
	For(i,1,n){
		int jb=0,dq=0;
		For(j,1,m)if(ch[i][j]=='#'){
			dq++;
		}else 
			if(dq&&!jb)jb=dq;
		if(jb!=dq&&jb)ans=-1;
	}
	For(j,1,m){
		int jb=0,dq=0;
		For(i,1,n)if(ch[i][j]=='#'){
			dq++;
		}else 
			if(dq&&!jb)jb=dq;
		if(jb!=dq&&jb)ans=-1;
	}
	cout<<ans<<endl;
}