#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool vis[1000001];
int cycles[1000001];
int sum[1000001];
const int mod = 1000000007;

int poww(int a, int b)
{
    if(b == 0) return 1;
    if(b & 1) return poww((long long)a * a % mod, b / 2) * (long long)a % mod;
    return poww((long long)a * a % mod, b / 2);
}

int main()
{
    int p, k;
    scanf("%d %d", &p, &k);
    if(k == 0)
    {
	printf("%d\n", poww(p, p - 1));
	return 0;
    }
    for(int i = 0; i < p; i++)
    {
	if(vis[i]) continue;
	vis[i] = true;
	int l = 1;
	for(int j = (long long)i * k % p; j != i; j = (long long)j * k % p)
	{
	    vis[j] = true;
	    l++;
	}
	cycles[l]++;
    }
    vector<int> vec;
    for(int i = 1; i <= p; i++)
	if(cycles[i]) vec.push_back(i);
    for(int i = 0; i < vec.size(); i++)
    {
	int l = vec[i] * cycles[vec[i]];
	for(int j = i; j < vec.size(); j++)
	    if(vec[j] % vec[i] == 0)
		sum[vec[j]] += l;
    }
    int ans = 1;
    for(int x: vec)
	ans = (long long)ans * poww(sum[x], cycles[x]) % mod;
    printf("%d\n", ans);
}