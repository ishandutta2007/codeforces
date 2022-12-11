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

const int primes[] = {2, 3, 5, 7};
int countPrimes[4];

void addDigit(int d)
{
	if (d < 2)
		return;
	for (int i = 0; i < 4; i++)
	{
		int cnt = 0;
		while (d % primes[i] == 0)
		{
			cnt++;
			d /= primes[i];
		}
		countPrimes[i] += cnt;
	}
}

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	string result = "";
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str[i] == '2' || str[i] == '3' || str[i] == '5' || str[i] == '7')
			result.push_back(str[i]);
		else if (str[i] == '4')
		{
			result.push_back('2');
			result.push_back('2');
			result.push_back('3');
		}
		else if (str[i] == '6')
		{
			result.push_back('3');
			result.push_back('5');
		}
		else if (str[i] == '8')
		{
			result.push_back('2');
			result.push_back('2');
			result.push_back('2');
			result.push_back('7');
		}
		else if (str[i] == '9')
		{
			result.push_back('2');
			result.push_back('3');
			result.push_back('3');
			result.push_back('7');
		}
	}
	sort(result.begin(), result.end());
	reverse(result.rbegin(), result.rend());
	cout << result;

	return 0;
}