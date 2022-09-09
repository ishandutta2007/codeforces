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

const int N=100050;
const int M=2*N;
map<char,int> go[M];
int link[M];
char s[N];
char* st[M];
int sz[M];
int cnt_leaf[M],n;
int root,tsz;

int AddNode(char*t,int len){
	tsz++;
	st[tsz]=t;
	sz[tsz]=len;
	link[tsz]=root;
	return tsz;
}

void BuildSuffixTree(){
	root=AddNode(NULL,0);
	link[root]=root;
	int atnode=root,atedge=0,atlen=0,pleaf=0,pnode=0;
	for(int i=0;i<=n;i++){
		while(1){
			int tonode=(atedge==n||go[atnode].count(s[atedge]))?go[atnode][s[atedge]]:0;
			if(tonode&&atlen>=sz[tonode]){
				atnode=tonode;
				atedge+=sz[tonode];
				atlen-=sz[tonode];
				continue;
			}
			if(!tonode){
				assert(atedge==i);
				if(i==n){
					cnt_leaf[atnode]++;
					if(pleaf)link[pleaf]=atnode;pleaf=0;
				}else{
					int leaf=AddNode(s+i,n-i);
					cnt_leaf[leaf]++;
					go[atnode][s[i]]=leaf;
					if(pleaf)link[pleaf]=leaf;pleaf=leaf;
				}
				if(pnode)link[pnode]=atnode;pnode=0;
			}else if(i==n||s[i]!=st[tonode][atlen]){
				int node=AddNode(st[tonode],atlen);
				st[tonode]+=atlen;sz[tonode]-=atlen;
				go[atnode][st[node][0]]=node;
				go[node][st[tonode][0]]=tonode;
				if(i==n){
					cnt_leaf[node]++;
					if(pleaf)link[pleaf]=node;pleaf=0;
				}else{
					int leaf=AddNode(s+i,n-i);
					cnt_leaf[leaf]++;
					go[node][s[i]]=leaf;
					if(pleaf)link[pleaf]=leaf;pleaf=leaf;
				}
				if(pnode)link[pnode]=node;pnode=node;
			}else{
				if(pnode)link[pnode]=atnode;pnode=0;
				atlen++;
				break;
			}
			if(atnode==root){
				atedge++;
				if(atlen>0)atlen--;
				else break;
			}else atnode=link[atnode];
		}
	}
}

ll C2(int x){return (ll)x*(x+1)/2;}

ll DFS(int u){
	ll ans=0;
	for(auto e:go[u]){
		int v=e.second;
		ans+=DFS(v);
		cnt_leaf[u]+=cnt_leaf[v];
		ans+=C2(cnt_leaf[v])*sz[v];
		//printf("%i %i\n",cnt_leaf[v],sz[v]);
	}
	return ans;
}

int main(){
	scanf("%s",s);
	n=strlen(s);
	BuildSuffixTree();
	printf("%lld\n",DFS(root));
	return 0;
}