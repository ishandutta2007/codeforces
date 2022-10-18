#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxLcmK = 360360;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

inline int gcd(int a, int b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}
inline int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int k;
int lcmK;

inline int calc(const int &a, const int &b)
{
	static int f[MaxLcmK];
	
	f[b] = 0;
	for (int i = b + 1; i <= a; i++)
	{
		f[i] = f[i - 1];
		for (int j = 1; j <= k; j++)
			if (i - i % j >= b)
				tension(f[i], f[i - i % j]);
		f[i]++;
	}
	return f[a];
}

int main()
{
	s64 a, b;
	
	cin >> a >> b >> k;
	
	lcmK = 1;
	for (int i = 1; i <= k; i++)
		lcmK = lcm(lcmK, i);
	
	s64 res;
	if (a / lcmK == b / lcmK)
		res = calc(a % lcmK, b % lcmK);
	else
		res = calc(a % lcmK, 0) + (calc(lcmK - 1, 0) + 1) * (a / lcmK - b / lcmK - 1) + calc(lcmK - 1, b % lcmK) + 1;
	cout << res << endl;
	
	return 0;
}