#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

vector<int> vec;

struct tree
{
    static const int offset = 1 << 19;
    int mx[offset << 1];
    
    tree()
    {
	for(int i = 0; i < (offset << 1); i++)
	    mx[i] = 0;
    }
    
    void insert(int a, int b, int k)
    {
	a = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
	b = lower_bound(vec.begin(), vec.end(), b) - vec.begin();
	a += offset;
	b += offset;
	while(a < b)
	{
	    if(a & 1)
	    {
		mx[a] = max(mx[a], k);
		a++;
	    }
	    if((b & 1) == 0)
	    {
		mx[b] = max(mx[b], k);
		b--;
	    }
	    a >>= 1;
	    b >>= 1;
	}
	if(a == b) mx[a] = max(mx[a], k);
    }
    
    int answer(int k)
    {
	k = lower_bound(vec.begin(), vec.end(), k) - vec.begin();
	k += offset;
	int ans = 0;
	while(k > 0)
	{
	    ans = max(ans, mx[k]);
	    k >>= 1;
	}
	return ans;
    }
};

int x[200000];
int y[200000];
char c[200000];
set<int> eaten;
tree left, up;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    vec.push_back(0);
    for(int i = 0; i < q; i++)
    {
	scanf("%d %d %c", x + i, y + i, c + i);
	vec.push_back(x[i]);
	vec.push_back(y[i]);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < q; i++)
    {
	if(eaten.count(x[i]))
	{
	    puts("0");
	    continue;
	}
	eaten.insert(x[i]);
	if(c[i] == 'L')
	{
	    int a = left.answer(y[i]);
	    up.insert(a, x[i], y[i]);
	    printf("%d\n", x[i] - a);
	}
	else
	{
	    int a = up.answer(x[i]);
	    left.insert(a, y[i], x[i]);
	    printf("%d\n", y[i] - a);
	}
    }
}