#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
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
const int N=200050;
const int M=10;
vector<pii> E[N],in[N];
bool bad[M][M][M][M];
int C[M];
int main(){
	int n,m,k;rd(n,m,k);
	for(int i=1,u,v,w;i<=m;i++)rd(u,v,w),E[u].pb({w,v});
	for(int i=1;i<=n;i++){
		sort(E[i].begin(),E[i].end());
		for(int j=0;j<E[i].size();j++){
			in[E[i][j].second].pb({(int)E[i].size(),j});
		}
	}
	for(int i=1;i<=n;i++){
		sort(in[i].begin(),in[i].end());
		for(int j=1;j<in[i].size();j++){
			if(in[i][j]==in[i][j-1]){
				bad[in[i][j].first][in[i][j].second][in[i][j].first][in[i][j].second]=1;
			}
		}
		in[i].erase(unique(in[i].begin(),in[i].end()),in[i].end());
		for(int j=0;j<in[i].size();++j){
			for(int l=j+1;l<in[i].size();++l){
				pii a=in[i][j];pii b=in[i][l];
				bad[a.first][a.second][b.first][b.second]=1;
				b=in[i][j];a=in[i][l];
				bad[a.first][a.second][b.first][b.second]=1;
			}
		}
	}
	for(int i=1;i<=k;i++)C[i]=0;
	int ans=0;
	while(1){
		bool ok=1;
		for(int i=1;i<=k;++i){
			for(int j=i;j<=k;++j){
				if(bad[i][C[i]][j][C[j]]){
					ok=0;
					break;
				}
			}
			if(!ok)break;
		}
		if(ok){
			ans++;
		}
		C[k]++;
		int ptr=k;
		while(ptr>0&&C[ptr]==ptr){
			C[ptr]=0;
			C[ptr-1]++;
			ptr--;
		}
		if(ptr==0)break;
	}
	printf("%i\n",ans);
	return 0;
}