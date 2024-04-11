#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 200000;

// getint
inline int getint()
{
    char c;
    while (c = getchar(), ('0' > c || c > '9') && c != '-');
    
    if (c != '-')
    {
        int res = c - '0';
        while (c = getchar(), '0' <= c && c <= '9')
            res = res * 10 + c - '0';
        return res;
    }
    else
    {
        int res = 0;
        while (c = getchar(), '0' <= c && c <= '9')
            res = res * 10 + c - '0';
        return -res;
    }
}

int main()
{
	int n, lim;
	static int a[MaxN + 1];

	cin >> n >> lim;
	for (int i = 1; i <= n; i++)
		a[i] = getint(); 

	int cnt = 0;
	s64 sum = 0;
	for (int i = 1; i <= n; i++)
	{
		s64 d = sum - (s64)cnt * (n - i) * a[i];
		if (d < lim)
			printf("%d\n", i);
		else
		{
			sum += (s64)cnt * a[i];
			cnt++;
		}
	}

	return 0;
}