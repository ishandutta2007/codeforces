#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int N=500005;
vector<int> v[N];
map<int,int> M[N];
int jj[N],s[N],t[N],dfn[N],low[N],sta[N],ans[N],zygay[N],st,ti;
void solve(vector<int> v){
	static int a[N];
	int n=v.size(),mx=0,MX=0,mn=1e9,MN=1e9;
	For(i,0,n-1)a[i]=M[v[i]][v[(i+1)%n]];
	For(i,0,n-1){
		if(a[i]>mx){mx=a[i]; MX=i;}
		if(a[i]<mn){mn=a[i]; MN=i;}
	}
	for(int i=MN;i!=MX;i=(i+1)%n){
		if(a[i]>a[(i+1)%n])return;
	}
	for(int i=MX;i!=MN;i=(i+1)%n){
		if(a[i]<a[(i+1)%n])return;
	}
	jj[a[MN]]=a[MX];
}
void dfs(int p,int fa){
	dfn[p]=low[p]=++ti;
	sta[++st]=p; 
	for(auto i:v[p]){
		if(i==fa)continue;
		if(!dfn[i]){
			dfs(i,p); low[p]=min(low[p],low[i]);
			if(low[i]>=dfn[p]){
				int x=0;
				vector<int> jb; 
				jb.pb(p);
				while(x^i){
					x=sta[st--];
					jb.pb(x);
				}//puts("zhu");
				solve(jb); //puts("fjhz");
			}
		}else low[p]=min(low[p],dfn[i]);
	}
}
int main(){
	int n=read(),m=read();
	For(i,1,m){
		s[i]=read(); t[i]=read();
		v[s[i]].pb(t[i]); v[t[i]].pb(s[i]);
		M[s[i]][t[i]]=i; M[t[i]][s[i]]=i;
	}
	For(i,1,n)if(!dfn[i])dfs(i,0);
	For(i,1,n)ans[i]=1; //cout<<jj[1]<<endl;
	Rep(i,m,1){
		if(jj[i]){
			ans[s[i]]-=zygay[jj[i]];
		}
		int sum=ans[s[i]]+ans[t[i]];
		zygay[i]+=sum;
		ans[s[i]]=ans[t[i]]=sum;
	}
	For(i,1,n)wri(ans[i]-1); 
}