#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define re(i,a) for (int i=0;i<a;++i)
#define clr(x) memset(x,0,sizeof x)
#define mp make_pair
#define N 555555
#define X first 
#define Y second
#define pb push_back
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
struct jc{
	int v,d;
	jc(){}
	jc(int v,int d):v(v),d(d){}
};
vector<jc> adj[N];
ll dis[N];
int n,f[N][25],dep[N],size[N];
int e[N][3];
bool use[N];
void dfs(int p){
	use[p]=1,++size[p];
	foreach(x,adj[p])if(!use[x->v]){
		use[x->v]=1;dep[x->v]=dep[p]+1;dis[x->v]=dis[p]+x->d;f[x->v][0]=p;
		for(int i=0;f[f[x->v][i]][i];++i)f[x->v][i+1]=f[f[x->v][i]][i];
		dfs(x->v);size[p]+=size[x->v];
	}
}
int ask(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	for(int i=20;i>=0;--i)if(dep[f[a][i]]>=dep[b])a=f[a][i];
	if(a==b)return a;
	for(int i=20;i>=0;--i)if(f[a][i]!=f[b][i])a=f[a][i],b=f[b][i];
	return f[a][0];
}
int main(){
	read(n);int x,y,z;
	rep(i,1,n-1) {
		read(x,y,z);
		e[i][0]=x,e[i][1]=y,e[i][2]=z;
		adj[x].pb(jc(y,z));
		adj[y].pb(jc(x,z));
	}
	dep[1]=1;
	dfs(1);
	ll sum=0,all=(ll)n*(n-1)*(n-2)/6;
	rep(i,1,n)foreach(x,adj[i])if(f[x->v][0]==i)sum+=(ll)x->d*size[x->v]*(n-size[x->v]);
	int m;
	scanf("%d",&m);
	for(int i=1,num,l;i<=m;++i)
	{
		scanf("%d %d",&num,&l);
		if(f[e[num][0]][0]==e[num][1])
			swap(e[num][0],e[num][1]);
		sum-=(ll)(e[num][2]-l)*size[e[num][1]]*(n-size[e[num][1]]),e[num][2]=l;
		printf("%.20f\n",1.0*sum*(n-2)/all);
	}
	return 0;
}