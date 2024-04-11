#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
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
const int N=100005;
int dfn[N],to[N],low[N],q[N],vis[N],zh[N],rd[N];
int ti,cnt;
vector<int> v[N],V[N],e[N];
void dfs(int p){
	dfn[p]=low[p]=++ti;
	vis[p]=zh[p]=1; q[++*q]=p;
	for(auto i:v[p]){
		if(!vis[i]){
			dfs(i); low[p]=min(low[p],low[i]);
		}else if(zh[i])low[p]=min(low[p],dfn[i]);
	}
	//cout<<dfn[p]<<" "<<low[p]<<" "<<q[*q]<<endl;
	if(dfn[p]==low[p]){
		cnt++;
		while(q[*q+1]!=p){
			to[q[*q]]=cnt; zh[q[*q]]=0; --*q;
		}
	}
}
int id(int x){
	return V[x].size()?V[x][V[x].size()-1]:-1;
}
int ask(int x,int y){
	putchar('?'); putchar(' '); wri(x); writeln(y); fflush(stdout);
	return read();
}
int main(){
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		int s=read(),t=read();
		v[s].push_back(t); 
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i); 
	for(int i=1;i<=n;i++){
		V[to[i]].push_back(i);
		for(auto j:v[i])if(to[i]!=to[j]){e[to[i]].push_back(to[j]); rd[to[j]]++;}
	}
	//for(int i=1;i<=n;i++)cout<<V[i][0]<<" "<<rd[i]<<endl;
	*q=0;
	for(int i=1;i<=cnt;i++)if(!rd[i])q[++*q]=i;
	for(int i=1;i<=*q;i++){
		if(*q==i){
			cout<<"! "<<id(q[i])<<endl; return 0;
		}
		while(id(q[i])!=-1&&id(q[i+1])!=-1){
			int t=ask(id(q[i]),id(q[i+1]));
			if(t)swap(q[i],q[i+1]);
			V[q[i]].pop_back();
		}
		for(auto j:e[q[i]])if(--rd[j]==0)q[++*q]=j;
	}
	
}
/*
4 2
1 2
3 4

*/