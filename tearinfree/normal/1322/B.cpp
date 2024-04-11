#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

int n,arr[400000],tmp[400000];

void f(int v) {
	vector<int> t[2];
	for(int i=0;i<n;i++) t[arr[i]>>v&1].push_back(arr[i]);
	for(int i=0,c=0;i<2;i++) for(auto &it: t[i]) arr[c++] = it;
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	
	int ans=0,t=1;
	for(int v=0;v<25;v++) {
		f(v);
		for(int i=0;i<n;i++) tmp[i] = arr[i], arr[i] &= t;

		for(int i=0;i<n;i++) {
			if((arr[i]>>v&1)^1) {
				int li = lower_bound(arr+i+1,arr+n, (1<<v) - (arr[i]&t)) - arr;
				int ri = upper_bound(arr+i+1,arr+n, t - (arr[i]&t)) - arr;
				if((ri-li)&1) ans ^= 1 << v;
			} else {
				int li = lower_bound(arr+i+1,arr+n, ((1<<v) | (1<<(v+1))) - (arr[i]&t)) - arr;
				int ri = upper_bound(arr+i+1,arr+n, (t<<1 | 1) - (arr[i]&t)) - arr;
				if((ri-li)&1) ans ^= 1 << v;
			}
		}
		t = t<<1 | 1;
		for(int i=0;i<n;i++) arr[i] = tmp[i];
	}
	printf("%d\n",ans);

	return 0;
}