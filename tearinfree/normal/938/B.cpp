#include <cstdio>
#include <algorithm>

using namespace std;

int n,arr[100000];

int main() {
	scanf("%d",&n);
	int mx = 0;
	for(int i=0;i<n;i++) {
		scanf("%d",arr+i);
		mx = max(mx, min(arr[i]-1, 1000000-arr[i]));
	}
	printf("%d\n",mx);
	return 0;
}