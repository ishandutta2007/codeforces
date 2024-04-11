#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=82;
int col[N];
int dist[N],tmp[N];
int edge[N][N],ans=1e9;
int n,k;
void Work(){
	for(int i=1;i<=n;i++)dist[i]=1e9;
	dist[1]=0;
	for(int l=1;l<=k;l++){
		for(int i=1;i<=n;i++){
			tmp[i]=1e9;
			for(int j=1;j<=n;j++)if(col[j]!=col[i])
				tmp[i]=min(tmp[i],dist[j]+edge[j][i]);
		}
		for(int i=1;i<=n;i++)dist[i]=tmp[i];
	}
	ans=min(ans,dist[1]);
}
int main(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%i %i",&n,&k);
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%i",&edge[i][j]);
	while(clock()<2.5*CLOCKS_PER_SEC){
		for(int i=1;i<=n;i++)col[i]=rng()%2;
		Work();
	}
	printf("%i\n",ans);
	return 0;
}