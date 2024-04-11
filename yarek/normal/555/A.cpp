#include <cstdio>
#include <vector>
using namespace std;

vector<int> aa[100000];
bool out[1000000];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = n - 1;
    for(int i = 0; i < k; i++)
    {
	auto &a = aa[i];
	int m;
	scanf("%d", &m);
	a.resize(m);
	for(int i = 0; i < m; i++)
	    scanf("%d", &a[i]);
	for(int i = 1; i < m; i++)
	    if(a[i] != a[i-1] + 1)
	    {
		out[a[i-1]] = true;
		out[a[i-1]+1] = true;
	    }
	out[a.back()] = true;
	out[a.back()+1] = true;
    }
    for(int i = 0; i < k; i++)
    {
	auto &a = aa[i];
	for(int j = 0;; j++)
	    if(out[a[j]] || j == a.size())
	    {
		ans += (int)a.size() - 2 * j - 1;
		break;
	    }
    }
    printf("%d\n", ans);
}