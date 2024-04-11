#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

const int MaxN = 500000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int n;
char s[MaxN + 1];
int nHouse;

inline int calc(int rest)
{
	int res = INT_MAX;
	static int f[MaxN + 1];
	
	int fail = -1;
	vector<int> failPos;
	
	int cur = 1;
	int cntHouse = 0;
	for (int i = 0; i < n; i++, cur++)
	{
		if (s[i] == 'H')
		{
			rest--;
			cntHouse++;
			if (rest == -1)
			{
				f[i] = cur;
				fail = i;
				failPos.push_back(i);
			}
		}
		else if (s[i] == 'S')
		{
			rest++;
			if (rest == 0 && fail != -1)
			{
				cur += (i - fail) * 2;
				fail = -1;
			}
		}
		
		if (cntHouse == nHouse && rest >= 0)
		{
			res = cur;
			for (vector<int>::iterator j = failPos.begin(); j != failPos.end(); j++)
				tension(res, f[*j] + (i - *j) * 2);
			break;
		}
	}
	return res;
}

int main()
{
	int time;

	cin >> n >> time;
	scanf("%s", s);

	nHouse = count(s, s + n, 'H');
	
	int l = 0, r = nHouse + 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (calc(mid) > time)
			l = mid + 1;
		else
			r = mid;
	}
	if (l == nHouse + 1)
		cout << -1 << endl;
	else
		cout << l << endl;

	return 0;
}