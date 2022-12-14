#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <vector>
#include <set>
#include <string>
using namespace std;
#define N 2050
#define mod 998244353
#define ll long long
int n,m,K;
ll f[N][N];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	int i,j;
	f[1][0]=m;
	for(i=2;i<=n;i++) {
		for(j=0;j<=K;j++) {
			f[i][j]=(f[i][j]+f[i-1][j])%mod;
			if(j+1<=K) f[i][j+1]=(f[i][j+1]+f[i-1][j]*(m-1))%mod;
		}
	}
	printf("%lld\n",f[n][K]);
}