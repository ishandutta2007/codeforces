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

const int N=2050;
char s[N][N];
int a[N][N];
vector<int> Make(int i,int j){
	vector<int> ans;
	for(int x=0;x<2;x++)for(int y=0;y<2;y++){
		if(x!=i||y!=j)ans.pb(x),ans.pb(y);
	}
	return ans;
}
vector<vector<int>> Solve(vector<vector<int>> mat){
	int sum=mat[0][0]+mat[0][1]+mat[1][0]+mat[1][1];
	if(sum==0)return {};
	vector<vector<int>> ans;
	if(sum==1){
		for(int i=0;i<2;i++)for(int j=0;j<2;j++){
			if(mat[i][j]==0)ans.pb(Make(i,j));
		}
	}else if(sum==2){
		for(int i=0;i<2;i++)for(int j=0;j<2;j++){
			if(mat[i][j]==1)ans.pb(Make(i,j));
		}
	}else if(sum==3){
		for(int i=0;i<2;i++)for(int j=0;j<2;j++){
			if(mat[i][j]==0)ans.pb(Make(i,j));
		}
	}else if(sum==4){
		for(int i=0;i<2;i++)for(int j=0;j<2;j++){
			ans.pb(Make(i,j));
		}
	}
	return ans;
}
int main(){
	for(int t=ri();t--;){
		int n,m;rd(n,m);
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=s[i][j]-'0';
			}
		}
		vector<vector<int>> ans;
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]){
					if(j==1){
						ans.pb({i,j,i+1,j,i+1,j+1});
						a[i][j]^=1;
						a[i+1][j]^=1;
						a[i+1][j+1]^=1;
					}else{
						ans.pb({i,j,i+1,j,i+1,j-1});
						a[i][j]^=1;
						a[i+1][j]^=1;
						a[i+1][j-1]^=1;
					}
				}
			}
		}
		for(int j=1;j<=m-2;j++){
			for(int i=n-1;i<=n;i++){
				if(a[i][j]){
					ans.pb({i,j,i,j+1,i==n?i-1:i+1,j+1});
					a[i][j]^=1;
					a[i][j+1]^=1;
					a[i==n?i-1:i+1][j+1]^=1;
				}
			}
		}
		vector<vector<int>> tmp=Solve({{a[n-1][m-1],a[n-1][m]},{a[n][m-1],a[n][m]}});
		for(vector<int> o:tmp){
			o[0]+=n-1;
			o[1]+=m-1;
			o[2]+=n-1;
			o[3]+=m-1;
			o[4]+=n-1;
			o[5]+=m-1;
			ans.pb(o);
		}
		printf("%i\n",ans.size());
		for(auto o:ans){
			for(int i:o)printf("%i ",i);
			printf("\n");
		}
	}
	return 0;
}