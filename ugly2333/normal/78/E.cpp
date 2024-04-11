//CF 78E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;

const int inf = 1e9;
struct edge{
	int pr;
	int to;
	int cap;
}e[111111];
int tot=1,la[1111];
void clr(){
	tot=1;
	memset(la,0,sizeof(la));
}
void adde(int x,int y,int z){
	e[++tot].pr=la[x];
	la[x]=tot;
	e[tot].to=y;
	e[tot].cap=z;
}
void addf(int x,int y,int z=inf){
	//printf("%d->%d %d\n",x,y,z);
	adde(x,y,z);
	adde(y,x,0);
}
int d[1111];
int bfs(int s,int t){
	queue<int> Q;
	int i,x,y;
	memset(d,0,sizeof(d));
	d[s]=1;
	Q.push(s);
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=la[x];i;i=e[i].pr){
			if(!e[i].cap)
				continue;
			y=e[i].to;
			if(!d[y]){
				d[y]=d[x]+1;
				Q.push(y);
			}
		}
	}
	return d[t];
}
int dfs(int s,int t,int f){
	if(s==t)
		return f;
	int i,x,y,r=0;
	for(i=la[s];i;i=e[i].pr){
		if(!e[i].cap||!f)
			continue;
		y=e[i].to;
		if(d[y]!=d[s]+1)
			continue;
		x=dfs(y,t,min(f,e[i].cap));
		if(x){
			f-=x;
			r+=x;
			e[i].cap-=x;
			e[i^1].cap+=x;
		}
	}
	if(!r)
		d[s]=0;
	return r;
}
int maxflow(int s,int t){
	int x,r=0;
	while(bfs(s,t)){
		x=dfs(s,t,inf);
		if(x)
			r+=x;
		else
			break;
	}
	return r;
}

const int N = 222;
int n,nn,l,st;
int a[N],b[N],c[N];
int t[N][N];
int main()
{
	char ch[22];
	int i,j,k,S,T,o;
	scanf("%d%d",&n,&l);
	nn=n*n;
	for(i=0;i<n;i=i+1){
		scanf("%s",&ch);
		for(j=0;j<n;j=j+1){
			k=i*n+j;
			if(ch[j]=='Y')
				a[k]=0;
			else{
				a[k]=1;
				if(ch[j]=='Z')
					st=k;
				else
					b[k]=ch[j]-48;
			}
		}
	}
	for(i=0;i<n;i=i+1){
		scanf("%s",&ch);
		for(j=0;j<n;j=j+1){
			k=i*n+j;
			if(a[k]&&k!=st)
				c[k]=ch[j]-48;
		}
	}
	for(i=0;i<nn;i=i+1)
		for(j=0;j<nn;j=j+1)
			if(i!=j)
				t[i][j]=inf;
	for(i=0;i<n;i=i+1)
		for(j=0;j<n-1;j=j+1){
			k=i*n+j;
			if(a[k]&&a[k+1])
				t[k][k+1]=1,t[k+1][k]=1;
		}
	for(i=0;i<n-1;i=i+1)
		for(j=0;j<n;j=j+1){
			k=i*n+j;
			if(a[k]&&a[k+n])
				t[k][k+n]=1,t[k+n][k]=1;
		}
	for(k=0;k<nn;k=k+1)
		for(i=0;i<nn;i=i+1)
			for(j=0;j<nn;j=j+1)
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
	clr();
	S=nn+nn,T=nn+nn+1;
	for(i=0;i<nn;i=i+1){
		if(!a[i])
			continue;
		if(b[i])
			addf(S,i,b[i]);
		if(c[i])
			addf(nn+i,T,c[i]);
	}
	for(i=0;i<nn;i=i+1)
		for(j=0;j<nn;j=j+1){
			if(b[i]&&c[j]&&t[i][j]<=l&&t[i][j]<=t[st][j]){
				o=0;
				for(k=0;k<nn;k=k+1)
					if(a[k]&&t[k][j]<=1&&t[i][k]<t[st][k])
						o=1;
				if(o)
					addf(i,nn+j);
			}
		}
	printf("%d",maxflow(S,T));
	return 0;
}