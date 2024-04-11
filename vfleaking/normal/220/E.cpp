#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

inline int lowbit(const int &a)
{
	return a & -a;
}

inline void bit_add(
		const int &n, int *bit,
		const int &index, const int &delta)
{
	for (int i = index; i <= n; i += lowbit(i))
		bit[i] += delta;
}
inline int bit_query(
		const int &n, int *bit,
		const int &index)
{
	int res = 0;
	for (int i = index; i >= 1; i -= lowbit(i))
		res += bit[i];
	return res;
}

int main()
{
	int n;
	static int a[MaxN + 1];
	s64 k;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	static int seq[MaxN + 1];
	copy(a + 1, a + n + 1, seq + 1);
	sort(seq + 1, seq + n + 1);
	int nVal = unique(seq + 1, seq + n + 1) - (seq + 1);
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(seq + 1, seq + nVal + 1, a[i]) - seq;
	
	s64 sum = 0ll;
	
	static int lbit[MaxN + 1], rbit[MaxN + 1];
	for (int i = 2; i <= n; i++)
	{
		bit_add(nVal, rbit, a[i], 1);
		sum += (i - 1) - bit_query(nVal, rbit, a[i]);
	}
	
	s64 res = 0ll;
	for (int i = 1, j = 2; i <= n && j <= n; i++)
	{
		bit_add(nVal, lbit, a[i], 1);
		sum += i - bit_query(nVal, lbit, a[i]);
		sum += bit_query(nVal, rbit, a[i] - 1);
		
		while (i == j || (j <= n && sum > k))
		{
			sum -= i - bit_query(nVal, lbit, a[j]);
			sum -= bit_query(nVal, rbit, a[j] - 1);
			bit_add(nVal, rbit, a[j], -1);
			
			j++;
		}
		res += n - j + 1;
	}
	
	cout << res << endl;
	
	return 0;
}