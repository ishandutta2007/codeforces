/*
Contest: -
Problem: Codeforces 1404E
Author: tzc_wk
Time: 2020.9.7
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int head[100005];
struct edge{
	int to,nxt,cap;
} e[1000005];
int ecnt=1;
inline void addedge(int u,int v,int f){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].nxt=head[u];head[u]=ecnt;
	e[++ecnt].to=u;e[ecnt].cap=0;e[ecnt].nxt=head[v];head[v]=ecnt;
}
int dep[100005];
inline bool bfs(int s,int t){
	queue<int> q;
	memset(dep,-1,sizeof(dep));
	q.push(s);dep[s]=0;
	while(!q.empty()){
		int cur=q.front();q.pop();
		for(int i=head[cur];i;i=e[i].nxt){
			int to=e[i].to;
			if(dep[to]==-1&&e[i].cap){
				dep[to]=dep[cur]+1;
				q.push(to);
			}
		}
	}
	if(dep[t]!=-1)	return 1;
	return 0;
}
inline int dfs(int x,int t,int f){
	if(x==t)	return f;
	int ret=0;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(dep[y]==dep[x]+1&&e[i].cap){
			int w=dfs(y,t,min(f-ret,e[i].cap));
			e[i].cap-=w;
			e[i^1].cap+=w;
			ret+=w;
			if(ret==f)	return f;
		}
	}
	if(ret==0)	dep[x]=-1;
	return ret;
}
inline int Dinic(int s,int t){
	int tot=0;
	while(bfs(s,t))	tot+=dfs(s,t,0x3f3f3f3f);
	return tot;
}
int n=read(),m=read();
inline int horz(int x,int y){
	return (x-1)*m+y;
}
inline int vert(int x,int y){
	return (x-1)*m+y+n*m;
}
char s[205][205];
int main(){
	int sum=0;
	fz(i,1,n) cin>>s[i]+1;
	fz(i,1,n) fz(j,1,m){
		sum+=(s[i][j]=='#');
		if(i!=n&&j!=m&&s[i][j]=='#'&&s[i+1][j]=='#'&&s[i][j+1]=='#') addedge(horz(i,j),vert(i,j),1);
		if(i!=1&&j!=m&&s[i][j]=='#'&&s[i-1][j]=='#'&&s[i][j+1]=='#') addedge(horz(i,j),vert(i-1,j),1);
		if(i!=n&&j!=1&&s[i][j]=='#'&&s[i+1][j]=='#'&&s[i][j-1]=='#') addedge(horz(i,j-1),vert(i,j),1);
		if(i!=1&&j!=1&&s[i][j]=='#'&&s[i-1][j]=='#'&&s[i][j-1]=='#') addedge(horz(i,j-1),vert(i-1,j),1);
	}
	int ss=0;
	fz(i,1,n) fz(j,1,m-1) if(s[i][j]=='#'&&s[i][j+1]=='#') ss++,addedge(0,horz(i,j),1);
	fz(i,1,n-1) fz(j,1,m) if(s[i][j]=='#'&&s[i+1][j]=='#') ss++,addedge(vert(i,j),2*n*m+1,1);
	cout<<sum-ss+Dinic(0,2*n*m+1)<<endl;
	return 0;
}//