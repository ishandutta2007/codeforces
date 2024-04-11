#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
		return positive ? x : -x;
}
const int N=400005;
int mmax,dist[N],ti,t1,t2,in[N],out[N],zs[N],nedge,n,m,nextt[N],son[N],ed[N],di[N],vis[N],que[N];
long long ans;
inline int dfs(int p,int fa){
	dist[p]=dist[fa]+1; in[p]=++ti;
	if(dist[p]>dist[mmax])mmax=p;
	for(int i=son[p];i;i=nextt[i])if(ed[i]!=fa)dfs(ed[i],p);
	out[p]=ti;
}
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; 
}
inline bool check(int a,int b){
	return in[a]<=in[b]&&out[a]>=out[b];
}
void ddd(int p,int fa){
	for(int i=son[p];i;i=nextt[i])if(ed[i]!=fa&&!check(ed[i],t1))ddd(ed[i],p);
	for(int i=son[p];i;i=nextt[i])if(ed[i]!=fa&&check(ed[i],t1))ddd(ed[i],p);
	if(p==t2)return;
	if(!check(p,t1)){
		write(zs[p]>dist[p]?t1:t2); putchar(' '); write(p); putchar(' '); writeln(p);
	}else{
		write(p); putchar(' '); write(t2); putchar(' '); writeln(p);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s1=read(),s2=read(); 
		aedge(s1,s2); aedge(s2,s1);
	}
	dist[0]=-1;
	dfs(1,0); t1=mmax;
	dfs(mmax,0);
	for(int i=1;i<=n;i++)zs[i]=dist[i];
	t2=mmax; ti=0; 
	dfs(mmax,0); 
	for(int i=1;i<=n;i++)if(!check(i,t1))ans+=max(dist[i],zs[i]);
	ans+=(long long)(dist[t1]-dist[t2])*(dist[t1]-dist[t2]+1)/2;
	cout<<ans<<endl;
	ddd(t2,0);
}