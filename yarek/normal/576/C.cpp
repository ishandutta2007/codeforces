#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int K = 1001;
vector<pair<int, int> > buc[K];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
	int x, y;
	scanf("%d %d", &x, &y);
	buc[x/K].emplace_back(y, i);
    }
    for(int i = 0; i < K; i++)
    {
	sort(buc[i].begin(), buc[i].end());
	if(i % 2) reverse(buc[i].begin(), buc[i].end());
	for(auto p: buc[i])
	    printf("%d ", p.second);
    }
    puts("");
}