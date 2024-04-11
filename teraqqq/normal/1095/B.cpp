#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int N = 1e5+7;

int n;
int a[N];

int stab(int* abegin, int* aend, int* ano) {
	int amax = 0, amin = 1e6;
	for(; abegin != aend; ++abegin) {
		if(abegin == ano) continue;
		if(amax < *abegin) amax = *abegin;
		if(amin > *abegin) amin = *abegin;
	}

	return amax - amin;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n; 
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	partial_sort(a, min(a+2, a+n), a+n, [](int a, int b) {
		return a > b;
	});

	if(n > 2) partial_sort(a+2, min(a+4, a+n), a+n, [](int a, int b) {
		return a < b;
	});

	int sz = min(4, n);
	int k = stab(a, a+sz, a);
	for(int i = 0; i < min(4, n); ++i) {
		k = min(k, stab(a, a+sz, a+i));
	}

	cout << k;
}