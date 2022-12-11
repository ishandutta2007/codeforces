#include "bits/stdc++.h"
using namespace std;

int dat[20][20];

vector<pair<int, int>> swaps;

bool cansortbefore(int arr[], int m, int idx)
{
	if (idx>=0) swap(arr[swaps[idx].first], arr[swaps[idx].second]);
	int diff = 0;
	for (int i = 0; i < m; i++) diff += (arr[i] != i + 1);
	if (idx>=0) swap(arr[swaps[idx].first], arr[swaps[idx].second]);
	return diff <= 2;
}

bool cansoftafter(int arr[], int m, int idx)
{
	if (idx < 0) return false;

	bool ret = false;
	for (auto &s : swaps)
	{
		swap(arr[s.first], arr[s.second]);
		swap(arr[swaps[idx].first], arr[swaps[idx].second]);
		if (is_sorted(arr, arr + m)) ret = true;
		swap(arr[swaps[idx].first], arr[swaps[idx].second]);
		swap(arr[s.first], arr[s.second]);
		if (ret) break;
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	if (m == 1)
	{
		printf("YES");
		return 0;
	}

	for (int i = 0; i < m - 1; i++) for (int j = i + 1; j < m; j++)
		swaps.emplace_back(i, j);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &dat[i][j]);
		}
	}

	for (int idx = -1; idx < (int)swaps.size(); idx++)
	{
		bool wrong = false;

		for (int i = 0; i < n; i++)
		{
			if (cansortbefore(dat[i], m, idx) == false &&
				cansoftafter(dat[i], m, idx) == false)
			{
				wrong = true; break;
			}
		}

		if (wrong == false) {
			printf("YES"); return 0;
		}
	}
	printf("NO");
}