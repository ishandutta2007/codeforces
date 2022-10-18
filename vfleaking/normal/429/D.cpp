#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long s64;

const s64 S64_MAX = 9223372036854775807ll;

const int MaxN = 100000;

s64 sqr(int x)
{
	return (s64)x * x;
}

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

int n;
int s[MaxN + 1];

s64 work(int qL, int qR)
{
	if (qL == qR)
		return S64_MAX;
	if (qL == 4 && qR == 5)
		cerr << "stop" << endl;

	int qMid = (qL + qR) / 2;
	s64 res = min(work(qL, qMid), work(qMid + 1, qR));
	int delta = res == S64_MAX ? n : (int)floor(sqrt(res));
	tension(delta, n);

	vector< pair<int, int> > vL, vR;
	for (int i = max(qL, qMid - delta); i <= qMid; i++)
		vL.push_back(make_pair(s[i], i));
	for (int i = qMid + 1; i <= min(qMid + delta, qR); i++)
		vR.push_back(make_pair(s[i], i));
	sort(vL.begin(), vL.end());
	sort(vR.begin(), vR.end());

	for (int i = 0, j = 0; i < (int)vL.size(); i++)
	{
		while (j < (int)vR.size() && vR[j].first < vL[i].first)
			j++;
		for (int k = max(0, j - 4); k < j + 4 && k < (int)vR.size(); k++)
			tension(res, sqr(vL[i].first - vR[k].first) + sqr(vL[i].second - vR[k].second));
	}
	return res;
}

int main()
{
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];

	cout << work(1, n) << endl;

	return 0;
}