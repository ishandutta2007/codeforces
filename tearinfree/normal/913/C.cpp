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
const lli inf=2e18;

inline int _abs(int a) {
	return a<0 ? -a : a;
}
inline lli _abs(lli a) {
	return a<0 ? -a : a;
}

int n,m;
lli arr[31];

lli dfs(int idx) {
	if(idx==-1) return 0;
	
	if(m&(1<<idx)) {
		return dfs(idx-1)+arr[idx];
	}
	else {
		return min(dfs(idx-1),arr[idx]);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<31;i++) arr[i]=inf;
	for(int i=0;i<n;i++) scanf("%lld",arr+i);
	n=31;
	
	for(int i=n-1;i>=0;i--) {
		lli cost=arr[i];
		for(int j=i+1;j<n;j++) {
			cost*=2;
			if(cost>=inf) cost=inf;
			arr[j]=min(arr[j],cost);
		}
	}

	printf("%lld\n",dfs(n-1));

	return 0;
}