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
const int N=85;
const int inf=1e9+7;
int dp[N][N][N*N];//dp[duzina][broj keceva][broj poteza]=min losih parova nula
int a[N],one[N],zer,ans[N*N];
int calc(int x){return x*(x-1)/2;}
int main(){
	int n=ri(),m=0;
	for(int i=1;i<=n;i++){
		rd(a[i]);
		if(a[i])one[++m]=i;
		else zer++;
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N*N;k++)dp[i][j][k]=inf;
	for(int k=0;k<N*N;k++)ans[k]=inf;
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++){//gde stoji poslednja jedinica
		for(int o=1;o<=m;o++){//broj keceva
			for(int j=0;j<i;j++){//velicina bloka nula pre
				for(int k=abs(one[o]-i);k<=n*(n-1)/2;k++){
					ckmn(dp[i][o][k],dp[i-1-j][o-1][k-abs(one[o]-i)]+calc(j));
				}
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int k=0;k<=n*(n-1)/2;k++){
			ckmn(ans[k],dp[i][m][k]+calc(n-i));
		}
	}
	for(int k=0;k<=n*(n-1)/2;k++){
		if(k)ckmn(ans[k],ans[k-1]);
		printf("%i ",calc(zer)-ans[k]);
	}
	return 0;
}