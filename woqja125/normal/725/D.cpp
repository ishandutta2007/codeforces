#include<stdio.h>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
pair<long long, long long> in[300001];
int main()
{
	int n, i, p=1, m = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%lld%lld", &in[i].first, &in[i].second);
	priority_queue <long long , vector<long long>, greater<long long >> H;
	std::sort(in + 1, in + n, greater<pair<long long, long long>>());
	for (; p < n && in[0].first < in[p].first; p++) {
		H.push(in[p].second - in[p].first + 1);
	}
	m = H.size();
	while (!H.empty()) {
		in[0].first -= H.top(); H.pop();
		if (in[0].first < 0) break;
		for (; p < n && in[0].first < in[p].first; p++) {
			H.push(in[p].second - in[p].first + 1);
		}
		if (m > H.size()) m = H.size();
	}
	printf("%d", m+1);
	return 0;
}