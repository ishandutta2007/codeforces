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
#include <cassert>
#include <complex>
#include <valarray>
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

bool isPrime(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

void composite()
{
	cout << "composite" << endl;
	exit(0);
}

void prime()
{
	cout << "prime" << endl;
	exit(0);
}

int main()
{
	for (int i = 2; i * i <= 100; i++)
	{
		if (isPrime(i))
		{
			cout << i << endl;
			string ans;
			cin >> ans;
			if (ans == "yes")
			{
				for (int s = 2; s * i <= 100; s++)
				{
					if (isPrime(s))
					{
						cout << s * i << endl;
						cin >> ans;
						if (ans == "yes")
							composite();
					}
				}
				prime();
			}
		}
	}
	prime();
	return 0;
}