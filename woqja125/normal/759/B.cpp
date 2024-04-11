#include<stdio.h>
#include<map>
using namespace std;
map<int, int> M;
int main()
{
	int n, t, bc=0;
	M[-100000] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		int min = bc + 20;
		
		auto it = M.lower_bound(t - 89); it--;
		if (min > it->second + 50) min = it->second + 50;

		it = M.lower_bound(t - 1439); it--;
		if (min > it->second + 120) min = it->second + 120;

		printf("%d\n", min - bc);
		bc = min;
		M[t] = bc;
	}
	return 0;
}