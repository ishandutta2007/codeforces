#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

const int N = 300000;
int a[N];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		vector<pair<int, int> > v;
		v.push_back(make_pair(a[0], a[0]));
		for (int i = 1; i < n; ++i) {
			if (a[i] > v.back().second) v.back().second = a[i];
			else v.push_back(make_pair(a[i], a[i]));
		}
		if (v.size() == 1 || v.front().first < v.back().second) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}