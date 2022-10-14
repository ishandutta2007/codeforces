#include <iostream>
using namespace std;

int max(int a, int b) {
	return a> b ? a : b;
}
int main() {
	int n; cin >> n;
	int v;
	int64_t x=0;
	int mx=0;
	for(int i=0;i<n; i++) {
		cin >> v;
		x+=v;
		mx=max(mx,v);
	}
	cout << (x%2==0&&x-mx>=mx?"YES":"NO");
	// 2 2 2 2 2
	// 1 1 1 1 2
	// 0 0 1 0 0
	// 3 3 3 3 3
	// 2 2 2 2 
}