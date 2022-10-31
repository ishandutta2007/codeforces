#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <complex>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;
typedef long long lli;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
const lli mod=1e9+7;
const int inf=1e9;

int n;
double arr[20][20],cache[1<<18];

double DP(int s) {
	double &ret=cache[s];
	if(ret>-0.5) return ret;

	if(s&1) return ret=0;
	else if(s==(1<<n)-2) return ret=1;
	
	ret=0;
	for(int i=0;i<n;i++) if(!(s&(1<<i))) {
		for(int j=i+1;j<n;j++) if(!(s&(1<<j))) {
			ret=max(ret,DP(s|(1<<i))*arr[j][i] + DP(s|(1<<j))*arr[i][j]);
		}
	}
	return ret;
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		scanf("%lf",&arr[i][j]);
	}

	for(int i=0;i<1<<n;i++) cache[i]=-1.0;
	
	printf("%.7lf\n",DP(0));

	return 0;
}