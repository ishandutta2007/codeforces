#include <cstdio>
#include <algorithm>

using namespace std;

int n,arr[5000],cnt[5001],res[5001];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",arr+i);
	}
	
	for(int i=0;i<n;i++) {
		for(int j=1;j<=n;j++) cnt[j]=0;
		
		int mx=0,idx=0;
		for(int j=i;j<n;j++) {
			cnt[arr[j]]++;
			if(mx<cnt[arr[j]] || (mx==cnt[arr[j]] && idx>arr[j])) {
				mx=cnt[arr[j]];
				idx=arr[j];
			}
			res[idx]++;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",res[i]);
	return 0;
}