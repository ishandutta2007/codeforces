/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int head[20005];
struct edge{
	int to,nxt,cap;
} e[3000005];
int ecnt=1;
inline void addedge(int u,int v,int f){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].nxt=head[u];head[u]=ecnt;
}
int dep[20005];
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
int x1[55],y1[55],x2[55],y2[55];
int keyx[205],keyy[205],cntx,cnty,hsx[205],hsy[205],idxx,idxy;
signed main(){
	fz(i,1,m){
		x1[i]=read();y1[i]=read();x2[i]=read();y2[i]=read();
		x2[i]++;y2[i]++;
		keyx[++cntx]=x1[i],keyx[++cntx]=x2[i];
		keyy[++cnty]=y1[i],keyy[++cnty]=y2[i];
	} 
	sort(keyx+1,keyx+cntx+1);
	sort(keyy+1,keyy+cnty+1);
	fz(i,1,cntx){
		if(keyx[i]!=keyx[i-1])	hsx[++idxx]=keyx[i];
	}
	fz(i,1,cnty){
		if(keyy[i]!=keyy[i-1])	hsy[++idxy]=keyy[i];
	}
	fz(i,1,m){
		x1[i]=lower_bound(hsx+1,hsx+idxx+1,x1[i])-hsx;
		x2[i]=lower_bound(hsx+1,hsx+idxx+1,x2[i])-hsx;
		y1[i]=lower_bound(hsy+1,hsy+idxy+1,y1[i])-hsy;
		y2[i]=lower_bound(hsy+1,hsy+idxy+1,y2[i])-hsy;
		fz(j,x1[i],x2[i]-1){
			fz(k,y1[i],y2[i]-1){
				addedge(j,k+200,0x3f3f3f3f);
				addedge(k+200,j,0);
			}
		}
	}
	fz(i,1,cntx-1){
		addedge(0,i,hsx[i+1]-hsx[i]);
		addedge(i,0,0);
	}
	fz(i,1,cnty-1){
		addedge(i+200,500,hsy[i+1]-hsy[i]);
		addedge(500,i+200,0);
	}
	cout<<Dinic(0,500)<<endl;
	return 0;
}