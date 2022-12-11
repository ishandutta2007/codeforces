#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set<pair<long long, int> > s;
int ans[200001];
long long mn[200001];
long long mx[200001];
long long l[200001];
long long r[200001];
long long a[200001];
vector<pair<long long, int>> vec;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
	scanf("%lld %lld", l + i, r + i);
    for(int i = 1; i <= m; i++)
    {
	scanf("%lld", a + i);
	vec.emplace_back(a[i], i);
    }
    for(int i = 1; i < n; i++)
    {
	mx[i] = r[i] - l[i-1];
	mn[i] = l[i] - r[i-1];
	vec.emplace_back(mn[i], -i);
    }
    sort(vec.begin(), vec.end());
    for(auto p: vec)
	if(p.second > 0)
	{
	    if(s.empty()) continue;
	    if(s.begin()->first < p.first)
	    {
		puts("No");
		return 0;
	    }
	    ans[s.begin()->second] = p.second;
	    s.erase(s.begin());
	}
	else s.insert(make_pair(mx[-p.second], -p.second));
    if(!s.empty()) puts("No");
    else
    {
	puts("Yes");
	for(int i = 1; i < n; i++)
	    printf("%d ", ans[i]);
	puts("");
    }
}