#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}


const bool debug=false;


const int mod=998244353;
int add(int a, int b){ a+=b;return a>=mod?a-mod:a;}
void ckadd(int &a, int b){ a=add(a,b);}
int sub(int a, int b){ a-=b;return a<0?a+mod:a;}
void cksub(int &a, int b){ a=sub(a,b);}
int mul(int a, int b){ return (ll)a*b%mod;}
void ckmul(int &a, int b){ a=mul(a,b);}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,ckmul(x,x)) if(k&1) ckmul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}

const int N=505;
int a[2*N][N];
multiset<int> ids[N][N],good;
bool active[N][N];
void Add(int col,int val,int id){
	if(!active[col][val])return;
	ids[col][val].insert(id);
	if(ids[col][val].size()==1){
		good.insert(id);
	}else if(ids[col][val].size()==2){
		auto it=ids[col][val].begin();
		int k=*it^*next(it)^id;
		good.erase(good.find(k));
	}
}
void Del(int col,int val,int id){
	if(!active[col][val])return;
	ids[col][val].erase(id);
	if(ids[col][val].size()==0){
		good.erase(good.find(id));
	}else if(ids[col][val].size()==1){
		good.insert(*ids[col][val].begin());
	}
}
vector<int> bad;
void Unc(int col,int val){
	if(ids[col][val].size()==1){
		good.erase(good.find(*ids[col][val].begin()));
	}
	for(int id:ids[col][val]){
		bad.pb(id);
	}
	ids[col][val].clear();
	active[col][val]=false;
}
vector<int> E[2*N],ans;
bool done[2*N];
int dep[2*N];
void DFS(int u){
	done[u]=true;
	if(dep[u]==0)ans.pb(u);
	for(int v:E[u]){
		if(!done[v]){
			dep[v]=dep[u]^1;
			DFS(v);
		}
	}
}
int main(){
	for(int t=ri();t--;){
		int n=ri();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				active[i][j]=true;
			}
		}
		for(int i=1;i<=2*n;i++){
			done[i]=false;
			for(int j=1;j<=n;j++){
				scanf("%i",&a[i][j]);
				Add(j,a[i][j],i);
			}
		}
		if(debug){for(int i:good)printf("%i ",i);printf("good\n");}
		ans.clear();
		int ways=1;
		while(good.size()){
			int id=*good.begin();
			//printf("%i\n",id);
			ans.pb(id);
			done[id]=true;
			for(int j=1;j<=n;j++){
				Del(j,a[id][j],id);
			}
			for(int j=1;j<=n;j++){
				Unc(j,a[id][j]);
			}
			//if(debug){for(int i:good)printf("%i ",i);printf("good\n");}
			for(int i:bad){
				if(done[i])continue;
				done[i]=true;
				for(int j=1;j<=n;j++){
					Del(j,a[i][j],i);
				}
			}
			bad.clear();
			//if(debug){for(int i:good)printf("%i ",i);printf("good\n");return 0;}
		}
		for(int col=1;col<=n;col++){
			for(int val=1;val<=n;val++){
				if(active[col][val]){
					assert(ids[col][val].size()==2);
					int x,y;
					x=*ids[col][val].begin();
					y=*next(ids[col][val].begin());
					E[x].pb(y);
					E[y].pb(x);
				}
			}
		}
		for(int i=1;i<=2*n;i++){
			if(!done[i]){
				DFS(i);
				ways=mul(ways,2);
			}
		}
		printf("%i\n",ways);
		for(int i:ans)printf("%i ",i);
		printf("\n");
		for(int i=1;i<=2*n;i++){
			E[i].clear();
			dep[i]=0;
			done[i]=false;
			for(int j=1;j<=n;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ids[i][j].clear();
				active[i][j]=0;
			}
		}
		good.clear();
		bad.clear();
	}
	return 0;
}