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

const int N=4050;
char s[N];

int go[N][12],tsz=1,root=1;
ll sum[N];
void Add(vector<int> ord,int C){
	int c=root;
	//for(int x:ord)printf("%c",'a'+x);printf(" for %i\n",C);
	for(int x:ord){
		if(!go[c][x]){
			go[c][x]=++tsz;
		}
		c=go[c][x];
	}
	sum[c]+=C;
}

int link[N];
vector<int> E[N];
void DFS(int u){
	for(int v:E[u]){
		sum[v]+=sum[u];
		DFS(v);
	}
}
void BuildAhoCorasick(){
	queue<int> q;
	for(int i=0;i<12;i++){
		if(!go[root][i]){
			go[root][i]=root;
		}else{
			link[go[root][i]]=root;
			q.push(go[root][i]);
		}
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<12;i++){
			if(!go[u][i]){
				go[u][i]=go[link[u]][i];
			}else{
				link[go[u][i]]=go[link[u]][i];
				q.push(go[u][i]);
			}
		}
	}
	for(int i=2;i<=tsz;i++)E[link[i]].pb(i);
	DFS(root);
}

const int M=1<<12;
ll dp[N][M];
int prevIdx[N][M];
int prevNode[N][M];

const ll inf=1e15;

void ckmx_save(int newNode,int newMask,ll value,int node,int idx){
	if(dp[newNode][newMask]<value){
		dp[newNode][newMask]=value;
		prevIdx[newNode][newMask]=idx;
		prevNode[newNode][newMask]=node;
	}
}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		int c=ri();
		scanf("%s",s+1);
		int m=strlen(s+1);
		vector<set<int>> E(12,set<int>{});
		for(int j=2;j<=m;j++){
			int u=s[j]-'a';
			int v=s[j-1]-'a';
			E[u].insert(v);
			E[v].insert(u);
		}
		bool ok=true;
		int root=-1;
		for(int j=0;j<12;j++){
			if(E[j].size()>2)ok=false;
			if(E[j].size()==1)root=j;
		}
		if(root==-1)ok=false;
		if(ok){
			vector<int> ord;
			while(E[root].size()){
				int next=*E[root].begin();
				E[next].erase(root);
				ord.pb(root);
				E[root].clear();
				root=next;
			}
			ord.pb(root);
			for(int j=0;j<12;j++){
				if(E[j].size()>0){
					ok=false;
				}
			}
			if(ok){
				Add(ord,c);
				reverse(ord.begin(),ord.end());
				Add(ord,c);
			}
		}
	}
	BuildAhoCorasick();
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dp[i][j]=-inf;
		}
	}
	dp[root][0]=0;
	for(int mask=0;mask<M-1;mask++){
        for(int u=1;u<=tsz;u++){
			for(int i=0;i<12;i++){
				if((mask>>i)&1){
					continue;
				}
				ckmx_save(go[u][i],mask|(1<<i),dp[u][mask]+sum[go[u][i]],u,i);
			}
			//if(dp[u][mask]>100)printf("(node:%i mask:%i) %lld\n",u,mask,dp[u][mask]);
        }
	}
	ll ans=0;
	int mask,node;
	for(int u=1;u<=tsz;u++){
		if(ans<=dp[u][M-1]){
			ans=dp[u][M-1];
			node=u;
			mask=M-1;
		}
	}
	string sol="";
	while(mask){
		sol+=('a'+prevIdx[node][mask]);
		int newMask=mask^(1<<prevIdx[node][mask]);
		int newNode=prevNode[node][mask];
		mask=newMask;
		node=newNode;
	}
	cout<<sol<<endl;
	//printf("%lld\n",ans);
	return 0;
}