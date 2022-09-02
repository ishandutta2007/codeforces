#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1005;
int fa[N],dep[N];
vector<int>e[N];
pair<int,int>ask(const vector<int>&v){
	printf("? %d ",SZ(v));
	for(auto&x:v)printf("%d ",x);
	puts("");
	fflush(stdout);
	int f,s;
	scanf("%d%d",&f,&s);
	return {f,s};
}
void report(int A,int B){
	printf("! %d %d\n",A,B);
	fflush(stdout);
	static char s[105];
	scanf("%s",s);
	assert(s[0]=='C');
}
vector<int>vec[N];
void dfs1(int k1,int k2,int k3){
	vec[k3].pb(k1),fa[k1]=k2;
	for(auto&x:e[k1])if(x!=k2){
		dep[x]=dep[k1]+1;
		dfs1(x,k1,k3+1);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		rep(i,1,n){
			e[i].clear(),e[i].shrink_to_fit();
			vec[i].clear(),vec[i].shrink_to_fit();
		}
		rep(i,2,n){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].pb(v),e[v].pb(u);
		}
		int root,minw;
		{
			vector<int>v;
			rep(i,1,n)v.pb(i);
			tie(root,minw)=ask(v);
		}
		dep[root]=0;
		dfs1(root,0,0);
		int l=(minw+1)/2,r=min(minw,*max_element(dep+1,dep+1+n)),A=root,B=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			int k1,k2;
			tie(k1,k2)=ask(vec[mid]);
			if(k2==minw){
				A=k1;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		if(minw==dep[A]){
			B=root;
		}else{
			vector<bool>vis(n+1);
			for(int x=A;x;x=fa[x]){
				vis[x]=1;
			}
			vector<int>v;
			for(auto&x:vec[minw-dep[A]]){
				if(!vis[x]){
					v.pb(x);
				}
			}
			B=ask(v).first;
		}
		report(A,B);
	}
	return 0;
}

/*

4 2

1
4
2 3
3 1
3 4
*/