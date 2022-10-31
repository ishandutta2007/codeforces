#include <cstdio>
#include <algorithm>

using namespace std;

int n,arr[100];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);

	sort(arr,arr+n);
	int t=15;
	for(int i=0;i<n;i++) {
		if(arr[i]>t) break;
		t=max(t,arr[i]+15);
	}
	printf("%d\n",min(t,90));
	return 0;
}