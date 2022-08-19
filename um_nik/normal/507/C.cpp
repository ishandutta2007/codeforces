#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

int h;
ll n;
ll v1, v2;

int main()
{
	cin >> h >> n;
	n--;
	v1 = v2 = 0LL;
	for (int i = 0; i < h; i++)
	{
		ll nv1, nv2;
		if (n & 1LL)
		{
			nv2 = v1 + 1LL;
			nv1 = (1LL << (i + 1)) + v1;
		}
		else
		{
			nv1 = v2 + 1LL;
			nv2 = (1LL << (i + 1)) + v2;
		}
		n /= 2LL;
		v1 = nv1;
		v2 = nv2;
	}
	cout << v1 << endl;

	return 0;
}