#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() 
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<pair<int, pair<bool, int> > > seg(2 * n);
	vector<int> end(n);
	int a, b;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		seg[i * 2] = make_pair(a, make_pair(0, i));
		seg[i * 2 + 1] = make_pair(b, make_pair(1, i));
		end[i] = b;
	}
	sort(seg.begin(), seg.end());
	set<pair<int, int> > s;
	vector<int> rm;
	for (int i = 0; i < 2 * n; ++i) {
		if (seg[i].second.first) s.erase(make_pair(end[seg[i].second.second], seg[i].second.second));
		else {
			s.insert(make_pair(end[seg[i].second.second], seg[i].second.second));
			if (s.size() > k) {
				rm.push_back(prev(s.end())->second);
				s.erase(prev(s.end()));
			}
		}
	}
	printf("%d\n", rm.size());
	for (int i = 0; i < rm.size(); ++i) printf("%d ", rm[i] + 1);
	printf("\n");
	return 0;
}