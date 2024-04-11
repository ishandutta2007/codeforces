#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 50;
int a[N];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		bool ok = false;
		int amt[2] = {0, 0};
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			++amt[a[i] & 1];
		}
		if (!(amt[0] & 1) && !(amt[1] & 1)) ok = true;
		sort(a, a + n);
		int x = !ok;
		if (!ok) for (int i = 1; i < n && !ok; ++i) {
			if (a[i] == a[i - 1] + 1 && (a[i - 1] & 1) != (a[i] & 1)) --x;
			if (!x) ok = true;
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}