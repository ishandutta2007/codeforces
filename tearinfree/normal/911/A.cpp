#include <cstdio>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;
typedef pair<int,int> pii;

int n;
pii arr[100000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].first),arr[i].second=i;
	sort(arr,arr+n);
	int mx=1e9;
	for(int i=1;i<n;i++) {
		if(arr[i].first==arr[i-1].first) {
			mx=min(mx,arr[i].second-arr[i-1].second);
		}
		else break;
	}
	printf("%d\n",mx);
	return 0;
}