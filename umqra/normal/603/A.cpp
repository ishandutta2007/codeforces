#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e6 + 10;
char str[N];
int x[N];

int main()
{
	int n;
	scanf("%d", &n);
	scanf(" %s", str);
	if (n == 1)
	{
		puts("1");
		return 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		x[i] = (str[i] - '0') ^ (str[i + 1] - '0');
	}
	int ans = 1;
	for (int i = 0; i < n - 1; i++)
		ans += x[i];
	int cntZero = 0;
	for (int i = 0; i < n - 1; i++)
		cntZero += (1 - x[i]);
	if (cntZero > 1)
		ans += 2;
	else if (cntZero == 1)
		ans++;
	
	printf("%d", ans);

	return 0;
}