#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000;
pair<int, int> b[N];
int a[N];

int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	sort(b, b + n);
	for (int i = 0; i < n; ++i) a[b[i].second] = i;
	vector<pair<int, pair<int, int> > > inv;
	for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i] > a[j]) inv.push_back(make_pair(i, make_pair(-a[j], j)));
	sort(inv.begin(), inv.end());
	printf("%d\n", inv.size());
	for (int i = 0; i < inv.size(); ++i) printf("%d %d\n", inv[i].first + 1, inv[i].second.second + 1);
	return 0;
}