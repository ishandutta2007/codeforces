#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
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

int cnt[100];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	int n;
	string str;
	cin >> n >> str;
	for (int i = 0; i < (int)str.length(); i++)
		cnt[str[i] - 'A']++;

	int maxCnt = 0;
	int cntMax = 0;
	for (int i = 0; i < 26; i++)
	{
		if (maxCnt < cnt[i])
		{
			maxCnt = cnt[i];
			cntMax = 1;
		}
		else if (maxCnt == cnt[i])
			cntMax++;
	}
	long long mod = (int)1e9 + 7;
	long long result = 1;
	for (int i = 0; i < n; i++)
	{
		result = (result * cntMax) % mod;
	}
	cout << result;

	return 0;
}