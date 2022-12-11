#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#pragma warning(disable: 6031)

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int i = 1 << 30;
		while (i > n) i >>= 1;
		printf("%d\n", i - 1);
	}
}