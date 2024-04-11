#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int p[100001];
bool u[100001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
	scanf("%d", p + i);
    vector<vector<int> > cycles;
    for(int i = 1; i <= n; i++)
	if(!u[i])
	{
	    vector<int> vec;
	    for(int k = i; !u[k]; k = p[k])
	    {
		u[k] = true;
		vec.push_back(k);
	    }
	    cycles.push_back(vec);
	}
    auto root = &*min_element(cycles.begin(), cycles.end(),
			     [](const vector<int> &a, const vector<int> &b) { return a.size() < b.size(); });
    vector<pair<int, int> > ans;
    if(root->size() == 2)
	ans.emplace_back(root->front(), root->back());
    if(root->size() > 2)
    {
	puts("NO");
	return 0;
    }
    for(auto &x: cycles)
    {
	if(&x == root) continue;
	if(x.size() % root->size() != 0)
	{
	    puts("NO");
	    return 0;
	}
	for(int i = 0; i < x.size(); i++)
	    ans.emplace_back(x[i], (*root)[i % root->size()]);
    }
    puts("YES");
    for(auto x: ans)
	printf("%d %d\n", x.first, x.second);
}