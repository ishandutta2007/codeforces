#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>

using namespace std;
typedef pair<int,int> pii;
typedef long long lli;
typedef pair<lli,lli> pll;

int n,k,arr[100001],t[100001],as[100001],ds[100001];

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",arr+i);
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",t+i);
		as[i] += as[i-1];
		ds[i] += ds[i-1];
		if(t[i] ==0) ds[i] += arr[i];
		else as[i]+=arr[i];
	}
	int mx=0;
	for(int i=1;i<=n-k+1;i++) {
		mx = max(mx, as[n] + ds[i+k-1] - ds[i-1]);
	}
	printf("%d\n",mx);
	return 0;
}