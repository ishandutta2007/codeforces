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

const int N=505;
const int M=N*N;

int type[M];//0 - leaf, 1 - P, 2 - Q
vector<int> go[M];
int tsz,root;
int color[M];//1 - white, 3 - grey, 2 - black

void init(int n){
	if(n==1){
		root=tsz=1;
	}else{
		root=tsz=n+1;
		type[root]=1;
		for(int i=1;i<=n;i++)go[root].pb(i);
	}
}

char *s;
void Paint(int u){
	if(type[u]==0){//leaf
		color[u]=s[u]=='1'?2:1;
	}else{
		color[u]=0;
		for(int v:go[u]){
			Paint(v);
			color[u]|=color[v];
		}
	}
}

int Merge(vector<int> nodes){
	if(nodes.empty())return 0;
	if(nodes.size()==1)return nodes[0];
	int node=++tsz;
	type[node]=1;
	go[node]=nodes;
	return node;
}

bool ok=true;
int Solve(int u,int t){
	if(!ok)return 0;
	if(color[u]!=3)return u;
	vector<int> ch[3];
	for(int v:go[u])ch[color[v]-1].pb(v);
	if(ch[2].size()>2||(t>0&&ch[2].size()>1)){ok=false;return 0;}
	if(type[u]==1){//P
		if(t==0){
			go[u]=ch[0];
			if(ch[2].size()==2||(ch[2].size()>0&&ch[1].size()>0)){
				int Q=Solve(ch[2][0],1);
				if(!ok)return 0;
				int b=Merge(ch[1]);
				if(b)go[Q].pb(b);
				if(ch[2].size()>1){
					int q=Solve(ch[2][1],2);
					if(!ok)return 0;
					for(int v:go[q])go[Q].pb(v);
				}
				go[u].pb(Q);
			}else if(ch[2].size()==1){
				int Q=Solve(ch[2][0],0);
				if(!ok)return 0;
				go[u].pb(Q);
			}else{
				int b=Merge(ch[1]);
				if(b)go[u].pb(b);
			}
		}else{
			type[u]=2;
			go[u].clear();
			int w=Merge(ch[0]);
			if(w)go[u].pb(w);
			if(ch[2].size()){
				int g=Solve(ch[2][0],1);
				if(!ok)return 0;
				for(int v:go[g])go[u].pb(v);
			}
			int b=Merge(ch[1]);
			if(b)go[u].pb(b);
			if(t==2)reverse(go[u].begin(),go[u].end());
		}
		if(go[u].size()==1)return go[u][0];
		return u;
	}else{//Q
		string pattern=t==0?"wgbgw":"wgb";
		int ptr=0;
		if(color[go[u][0]]==2||color[go[u].back()]==1)reverse(go[u].begin(),go[u].end());
		vector<int> ngo;
		/*printf("Q %i: ",u);
		for(int v:go[u]){
			char col=color[v]==1?'w':color[v]==2?'b':'g';
			printf("%c ",col);
		}
		printf("\n");*/
		bool strict=t!=0||ch[2].size()>1||(ch[2].size()>0&&ch[1].size()>0);
		for(int v:go[u]){
			char col=color[v]==1?'w':color[v]==2?'b':'g';
			while(ptr<pattern.size()&&pattern[ptr]!=col)ptr++;
			if(ptr==pattern.size()){ok=false;return 0;}
			if(color[v]!=3){//white or black
				ngo.pb(v);
			}else{//grey
				int Q;
				if(!strict)Q=Solve(v,0);
				else if(ptr==1)Q=Solve(v,1);
				else Q=Solve(v,2);
				if(!ok)return 0;
				if(!strict)ngo.pb(Q);
				else for(int h:go[Q])ngo.pb(h);
				ptr++;
			}
		}
		go[u]=ngo;
		if(t==2)reverse(go[u].begin(),go[u].end());
		return u;
	}
}

void AddSet(char *t){
	if(!ok)return;
	s=t;
	Paint(root);
	root=Solve(root,0);
}

void Print(int u){
	if(type[u]==0){
		printf("%i ",u);
	}else{
		if(type[u]==1){
			printf("P{ ");
		}else printf("Q[ ");
		for(int v:go[u])Print(v);
		if(type[u]==1){
			printf("} ");
		}else printf("] ");
	}
}

const int mod=998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}
int F[N];

int ans=1;
vector<int> ord;
void DFS(int u){
	if(type[u]==0){
		ord.pb(u);
	}else{
		if(type[u]==1)ans=mul(ans,F[go[u].size()]);
		else ans=mul(ans,2);
		for(int v:go[u])DFS(v);
	}
}

char mask[N];

int main(){
	int n,m;
	rd(n,m);
	init(n);
	F[0]=1;
	for(int i=1;i<N;i++)F[i]=mul(F[i-1],i);
	for(int i=1;i<=m;i++){
		int q=ri();
		for(int j=1;j<=n;j++)mask[j]='0';
		while(q--){
			int u=ri();
			mask[u]='1';
		}
		AddSet(mask);
	}
	if(!ok)printf("0\n");
	else{
		DFS(root);
		printf("%i\n",ans);
	}
	return 0;
}