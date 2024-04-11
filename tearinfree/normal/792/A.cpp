#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

int n,arr[200000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",arr+i);
	sort(arr,arr+n);

	int mx=2e9+1,cnt=1;
	for(int i=1;i<n;i++) {
		int dif=arr[i]-arr[i-1];
		if(dif<mx) {
			mx=dif; cnt=1;
		}
		else if(dif==mx) {
			cnt++;
		}
	}
	printf("%d %d\n",mx,cnt);
	return 0;
}