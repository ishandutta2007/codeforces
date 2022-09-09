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

int link[M],sz[M],leaf_cnt[M],sub[M];
char* st[M];
char s[N];
int tsz,root,n;
map<char,int> go[M];

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
			int tonode=(atedge==n||!go[atnode].count(s[atedge]))?0:go[atnode][s[atedge]];
			if(tonode&&atlen>=sz[tonode]){
				atnode=tonode;
				atlen-=sz[tonode];
				atedge+=sz[tonode];
				continue;
			}
			if(!tonode){
				assert(atedge==i);
				if(i==n){
					leaf_cnt[atnode]++;
					if(pleaf)link[pleaf]=atnode;pleaf=0;
				}else{
					int leaf=AddNode(s+i,n-i);
					leaf_cnt[leaf]++;
					go[atnode][s[i]]=leaf;
					if(pleaf)link[pleaf]=leaf;pleaf=leaf;
				}
				if(pnode)link[pnode]=atnode;pnode=0;
			}else if(i==n||st[tonode][atlen]!=s[i]){
				int node=AddNode(st[tonode],atlen);
				st[tonode]+=atlen;sz[tonode]-=atlen;
				go[atnode][st[node][0]]=node;
				go[node][st[tonode][0]]=tonode;
				if(i==n){
					leaf_cnt[node]++;
					if(pleaf)link[pleaf]=node;pleaf=0;
				}else{
					int leaf=AddNode(s+i,n-i);
					leaf_cnt[leaf]++;
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

void Pre(int u){
	sub[u]=leaf_cnt[u];
	for(auto e:go[u]){
		int v=e.second;
		Pre(v);
		sub[u]+=sub[v];
	}
}

int k,asz;
char ans[N];
void DFS(int u){
	//printf("%i %i\n",u,sub[u]);
	for(auto e:go[u]){
		int v=e.second;
		for(int i=0;i<sz[v];i++){
			ans[asz++]=st[v][i];
			k-=sub[v];
			if(k<=0){
				ans[asz]=0;
				printf("%s\n",ans);
				exit(0);
			}
		}
		DFS(v);
		asz-=sz[v];
	}
}

int main(){
	rd(s);
	n=strlen(s);
	BuildSuffixTree();
	k=ri();
	Pre(root);
	DFS(root);
	printf("No such line.");
	return 0;
}