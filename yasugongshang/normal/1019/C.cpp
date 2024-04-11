#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=1000005;
int vis[N],n,m,jb[N];
vector<int> v[N],ans;
void dfs(int p){
	if(p>n)return;
	if(vis[p]){
		dfs(p+1); return;
	}
	for(unsigned i=0;i<v[p].size();i++)vis[v[p][i]]=1; vis[p]=1;
	dfs(p+1);
	if(!jb[p]){
		ans.push_back(p);
		for(unsigned i=0;i<v[p].size();i++)jb[v[p][i]]=1;
	}
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		int s=read(),t=read();
		v[s].push_back(t); 
	}
	dfs(1);
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(unsigned i=0;i<ans.size();i++){
		write(ans[i]); putchar(' ');
	}
}