#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int N = 100000;

int a[N];

void testcase() 
{
	int n, k;
	scanf("%d%d", &n, &k);
	bool ok = false;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if (a[i] == k) ok = true;
	}
	if (!ok) {
		printf("no\n");
		return;
	}
	if (n == 1) {
		printf("yes\n");
		return;
	}
	multiset<int> x;
	x.insert(a[0]);
	ok = false;
	for (int i = 1; i < n; ++i) {
		x.insert(a[i]);
		if (*x.begin() >= k) {
			ok = true;
		}
		x.erase(x.find(a[i - 1]));
	}
	if (n == 2) {
		if (ok) printf("yes\n");
		else printf("no\n");
		return;
	}
	if (ok) {
		printf("yes\n");
		return;
	}
	x.clear();
	x.insert(a[0]);
	x.insert(a[1]);
	for (int i = 2; i < n; ++i) {
		x.insert(a[i]);
		if (*next(x.begin()) >= k) {
			ok = true;
		}
		x.erase(x.find(a[i - 2]));
	}
	if (ok) printf("yes\n");
	else printf("no\n");
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		testcase();
	}
	return 0;
}