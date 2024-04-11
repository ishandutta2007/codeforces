#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
constexpr int max_n=1000;
int a[max_n+1],ideg[max_n+1];
bool f[max_n+1][max_n+1];
int stk[max_n+1];
vector<int>g[max_n+1];
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i),ideg[i]=0,g[i].clear();
		if(a[i]>n){
			for(int j=n; j; --j)
				f[i][j]=1;
			(a[i]-=n)%=mod;
		}
		else{
			for(int j=a[i]; j; --j)
				f[i][j]=1;
			for(int j=a[i]; ++j<=n; f[i][j]=0);
			a[i]=0;
		}
	}
	for(int i=m,u,v; i; --i,g[u].emplace_back(v),++ideg[v])
		scanf("%d%d",&u,&v);
	int top=0;
	for(int i=1; i<=n; ++i)
		if(!ideg[i])
			stk[++top]=i;
	while(top){
		const int u=stk[top];
		--top;
		if(g[u].empty()){
			int lst=0;
			for(int j=1; j<=n; ++j)
				if(f[u][j])
					lst=j;
			if(lst==n)
				(lst+=a[u])>=mod&&(lst-=mod);
			printf("%d\n",lst);
			return;
		}
		for(const int&v:g[u]){
			for(int j=1,k=1; j<=n; ++j){
				if(!f[u][j])
					continue;
				if(k<=j)
					k=j+1;
				while(k<=n&&f[v][k])
					++k;
				if(k<=n)
					f[v][k]=1;
				else
					++a[v];
			}
			a[v]%=mod;
			(a[v]+=a[u])>=mod&&(a[v]-=mod);
			if(!--ideg[v])
				stk[++top]=v;
		}
	}
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}