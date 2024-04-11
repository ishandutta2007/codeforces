#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <map>
#include <set>

using namespace std;
typedef long long lli;

int n;
lli arr[1000001];
lli sum[1000001];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",arr+i);
	bool flag=false;
	for(int i=1;i<=n;i++) {
		sum[i]=arr[i]+sum[i-1];
		if(sum[i]&1) flag=true;
	}
	if(flag) puts("First");
	else puts("Second");
	return 0;
}