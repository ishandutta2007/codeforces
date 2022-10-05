//Coded by tzc_wk
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
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
typedef pair<int,int> pii;
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
int n=read(),k=read(),a[105],b[105],c[105];
bool is[1000005];
inline void getpr(){
	fz(i,2,1000000){
		if(!is[i]){
			for(int j=i+i;j<=1000000;j+=i)	is[j]=1;
		}
	}
}
int head[200005];
struct edge{
	int to,nxt,cap;
} e[3000005];
int ecnt=1;
inline void addedge(int u,int v,int f){
	e[++ecnt].to=v;e[ecnt].cap=f;e[ecnt].nxt=head[u];head[u]=ecnt;
	e[++ecnt].to=u;e[ecnt].cap=0;e[ecnt].nxt=head[v];head[v]=ecnt;
}
int dep[200005];
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
inline bool check(int mid){
	fill0(head);ecnt=1;
	vector<pii> np;
	int mx=0,ind=-1;
	fz(i,1,n){
		if(c[i]>mid)	continue;
		if(b[i]==1){
			if(mx<a[i])	ind=i,mx=a[i];
		}
		else{
			np.push_back({a[i],b[i]});
		}
	}
	if(~ind)	np.push_back({mx,1});
	for(int i=0;i<np.size();i++){
		for(int j=0;j<np.size();j++){
			if(i==j)	continue;
			if(!is[np[i].se+np[j].se])	addedge(i+1,j+n+1,0x3f3f3f3f);
		}
	}
	int sum=0;
	for(int i=0;i<np.size();i++){
		addedge(0,i+1,np[i].fi);
		addedge(i+n+1,5000,np[i].fi);
		sum+=np[i].fi;
//		cout<<np[i].fi<<" "<<np[i].se<<endl;
	}
//	cout<<Dinic(0,5000)<<endl;
	return sum-Dinic(0,5000)/2>=k;
}
signed main(){
	getpr();
	fz(i,1,n)	a[i]=read(),b[i]=read(),c[i]=read();
//	check(6);
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))	ans=mid,r=mid-1;
		else			l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}