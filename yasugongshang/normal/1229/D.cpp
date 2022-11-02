#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
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
map<poly,int> M;
poly ys[120],vvv;
int n,k,cnt,b[N],ycl[120][120],q[125];
bitset<120> vis;
ll ans;
poly operator *(poly &a,poly &b){
	poly c(k);
	For(i,0,k-1)c[i]=b[a[i]];
	return c;
}
void dfs(int p){
	if(p==k){
		ys[cnt]=vvv; M[vvv]=cnt++; return;
	}
	For(i,0,k-1)if(!vis[i]){vis[i]=1; vvv[p]=i; dfs(p+1); vis[i]=0;} 
}
int main(){
	n=read(),k=read();
	vvv.resize(k);
	dfs(0);
	b[n+1]=-1;
	For(i,1,n){poly zs(k); For(j,0,k-1)zs[j]=read()-1; b[i]=M[zs];}
	vector<int> dq(1); dq[0]=n+1;
	For(i,0,cnt-1)For(j,0,cnt-1)ycl[i][j]=M[ys[i]*ys[j]];
	Rep(i,n,1){
		vector<int> v;
		v.pb(i);
		for(auto j:dq)if(b[j]!=b[i])v.pb(j);
		int sz=v.size();
		vis.reset(); *q=1;  vis[0]=1;
		vector<int> alb;
		For(i,0,sz-2){
			int j=v[i],o=b[j];
			if(!vis[o]){
				alb.pb(o);
				For(l,1,*q){
					for(auto o:alb)if(!vis[ycl[q[l]][o]])vis[q[++*q]=ycl[q[l]][o]]=1;
				}
				
			}
			//<<i+1<<" "<<v.size()-1<<" "<<v[v.size()-1]<<endl;
			//cout<<v[i]<<" "<<v[i+1]<<" "<<o<<" "<<*q<<" "<<v[i+1]-v[i]<<endl;
			ans+=(*q)*(v[i+1]-v[i]);
		}
		swap(dq,v);
	}
	cout<<ans<<endl;
}