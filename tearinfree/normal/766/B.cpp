#include <cstdio>
#include <algorithm>

using namespace std;

int n,arr[100000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	sort(arr,arr+n);

	for(int i=0;i<n-2;i++) {
		if(arr[i+2] < arr[i]+arr[i+1]) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");

	return 0;
}