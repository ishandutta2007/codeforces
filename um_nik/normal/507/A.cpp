#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1000;
int n;
int k;
pii a[N];
vector<int> ans;


int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = mp(x, i + 1);
	}
	sort(a, a + n);
	for (int i = 0; i < n && k >= a[i].first; i++)
	{
		k -= a[i].first;
		ans.push_back(a[i].second);
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}