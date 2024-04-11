#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin>>n>>k;
	static int a[100<<10];
	for(int i=0;i<n;i++) cin>>a[i];
	int i=0;
	--k;
	for(;;) {
		++i;
		if(k<i) return cout<<a[k]<<endl,0;
		k-=i;
	}
}