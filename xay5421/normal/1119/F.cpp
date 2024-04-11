#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define EB emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=250005;
int n;
int deg[N],id[N],nowt,vis[N];
LL f[N][2];
vector<pair<int,int> >G[N];
struct HEAP{
	vector<LL>A,B;
	LL sum;
	void ins(LL x){
		A.PB(x);
		sum+=x;
		push_heap(A.begin(),A.end());
	}
	void del(LL x){
		B.PB(x);
		sum-=x;
		push_heap(B.begin(),B.end());
	}
	void clip(){
		while(SZ(A)&&SZ(B)&&A[0]==B[0]){
			pop_heap(A.begin(),A.end()),A.pop_back();
			pop_heap(B.begin(),B.end()),B.pop_back();
		}
	}
	int top(){
		clip();
		assert(SZ(A));
		return A[0];
	}
	void pop(){
		clip();
		assert(SZ(A));
		sum-=A[0];
		pop_heap(A.begin(),A.end()),A.pop_back();
	}
	int size(){return SZ(A)-SZ(B);}
}H[N];
void del(int k1){
	for(auto j:G[k1]){
		if(deg[j.X]<=nowt)break;
		H[j.X].ins(j.Y);
	}
}
vector<LL>I,D;
void dfs(int k1,int k2){
	vis[k1]=nowt;
	for(auto j:G[k1])if(j.X!=k2){
		if(deg[j.X]<=nowt)break;
		dfs(j.X,k1);
	}
	int ned=deg[k1]-nowt;
	LL res=0;
	while(SZ(H[k1])>ned)H[k1].pop();
	I.clear(),D.clear();
	for(auto j:G[k1])if(j.X!=k2){
		if(deg[j.X]<=nowt)break;
		LL x=f[j.X][1]+j.Y-f[j.X][0];
		res+=f[j.X][0];
		if(x<=0){--ned,res+=x;continue;}
		H[k1].ins(x),D.PB(x);
	}
	while(SZ(H[k1])&&SZ(H[k1])>ned)I.PB(H[k1].top()),H[k1].pop();
	f[k1][0]=res+H[k1].sum;
	while(SZ(H[k1])&&SZ(H[k1])>ned-1)I.PB(H[k1].top()),H[k1].pop();
	f[k1][1]=res+H[k1].sum;
	for(auto x:I)H[k1].ins(x);
	for(auto x:D)H[k1].del(x);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,2,n){
		int k1,k2,k3;
		scanf("%d%d%d",&k1,&k2,&k3);
		G[k1].EB(k2,k3),G[k2].EB(k1,k3);
		++deg[k1],++deg[k2];
	}
	rep(i,1,n)id[i]=i;
	sort(id+1,id+1+n,[&](int k1,int k2){return deg[k1]<deg[k2];});
	rep(i,1,n){
		sort(G[i].begin(),G[i].end(),[&](const pair<int,int>&k1,const pair<int,int>&k2){
			return deg[k1.X]>deg[k2.X];
		});
	}
	memset(vis,-1,sizeof(vis));
	for(int d=0,i=1;d<n;++d){
		while(i<=n&&deg[id[i]]==d){
			del(id[i]);
			++i;
		}
		nowt=d;
		LL ans=0;
		//D(">>> %d\n",d);
		rep(j,i,n)if(vis[id[j]]!=nowt){
			dfs(id[j],0);
			ans+=f[id[j]][0];
		}
		printf("%lld ",ans);
	}
	return 0;
}