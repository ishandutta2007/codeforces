#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int n;
	scanf("%d", &n);
	vector<int> d(n + 1, 1);
	for (int i = 2; i <= n; ++i) {
		for (int j = i * 2; j <= n; j += i) d[j] = i;
	}
	sort(d.begin(), d.end());
	for (int i = 2; i <= n; ++i) printf("%d ", d[i]);
	printf("\n");
	return 0;
}