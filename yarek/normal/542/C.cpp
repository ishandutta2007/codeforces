#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long nwd(long long a, long long b)
{
    while(b != 0)
    {
	long long c = a % b;
	a = b;
	b = c;
    }
    return a;
}

long long nww(long long a, long long b)
{
    return a * b / nwd(a, b);
}

bool cycle[201];
int f[201];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    long long NWW = 1;
    for(int i = 1; i <= n; i++)
	cin >> f[i];
    for(int i = 1; i <= n; i++)
    {
	int k = i;
	for(int j = 1; j <= n; j++)
	{
	    k = f[k];
	    if(k == i)
	    {
		NWW = nww(NWW, j);
		cycle[i] = true;
		break;
	    }
	}
    }
    int maxdist = 0;
    for(int i = 1; i <= n; i++)
    {
	int k = i;
	for(int j = 0; j <= n; j++)
	{
	    if(cycle[k])
	    {
		maxdist = max(maxdist, j);
		break;
	    }
	    k = f[k];
	}
    }
    long long ans = max((maxdist + NWW - 1) / NWW * NWW, NWW);
    cout << ans << endl;
}