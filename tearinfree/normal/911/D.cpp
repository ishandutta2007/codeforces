#include <cstdio>
#include <algorithm>

using namespace std;

int n,arr[1500];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	int cnt=0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(arr[i]>arr[j]) {
		cnt^=1;
	}
	int m;
	scanf("%d",&m);
	while(m--) {
		int l,r;
		scanf("%d%d",&l,&r);
		int t=r-l+1,val=t*(t-1)/2;
		if(val&1) cnt^=1;
		puts(cnt&1 ? "odd" : "even");
	}
	return 0;
}