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
const int N=1000005;
int n,k,fa[N],f[N],g[N],h[N];
vector<int> v[N];
void dfs(int p){
	if(v[p].size()==0){
		f[p]=g[p]=1; return;
	}
	int mx=0; h[p]=N;
	for(auto i:v[p]){
		dfs(i);
		if(++h[i]>k){
			g[i]=0;
		}
		g[p]+=g[i]; h[p]=min(h[p],h[i]);
		mx=max(mx,f[i]-g[i]);
	}
	f[p]=g[p]+mx;
	//cout<<f[p]<<" "<<h[p]<<" "<<g[p]<<endl;
}
int main(){
	n=read(); k=read();
	for(int i=2;i<=n;i++){
		fa[i]=read(); v[fa[i]].push_back(i);
	}
	dfs(1);
	cout<<f[1]<<endl;
}