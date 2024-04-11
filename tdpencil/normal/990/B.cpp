#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
#define pb push_back
const int MAXN = 2e5 + 1;
int a[MAXN];
int dif[MAXN - 1];
void go() {
	int n, k ; scanf("%d%d", &n, &k);
	vector<int> v;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
	}
	
	sort(a, a + n);
	
	for(int i = 0; i < n; i++) {
		while(!v.empty() && a[i] > v.back() && a[i] - v.back() <= k) {
			v.pop_back();
		}
		v.push_back(a[i]);
	}
	
	
	printf("%d", (int)v.size());
	
	
}

int main() {
	int t = 1; // scanf("%d", &t);
	while(t--) go();
}