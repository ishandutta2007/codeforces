#include <iostream>
#include <algorithm>

const int ms = 110;

struct person
{
	int freq = 0, last = -1, idx;
};

bool cmp(person a, person b)
{
	return a.freq > b.freq || (a.freq == b.freq && a.last < b.last);
}

person arr[ms];
int ans[ms];

int main()
{
	int n, k, m, a;
	std::cin >> n >> k >> m >> a;
	for(int i = 0; i < n; i++)
		arr[i].idx = i;
	for(int i = 0; i < a; i++)
	{
		int temp;
		std::cin >> temp;
		temp--;
		arr[temp].freq++;
		arr[temp].last = i;
	}
	std::sort(arr, arr + n, cmp);
	//for(int i = 0; i < n; i++)
	//	std::cout << arr[i].idx << ": " << arr[i].freq << ", " << arr[i].last << "\n";
	if(a == m)
	{
		for(int i = 0; i < k; i++)
		{
			if(arr[i].freq)
				ans[arr[i].idx] = 1;
			else
				ans[arr[i].idx] = 3;
		}
		for(int i = k; i < n; i++)
			ans[arr[i].idx] = 3;
	}
	else if(k < n)
	{
		for(int i = 0; i < k; i++)
		{
			int got = 0;
			ans[arr[i].idx] = 1;
			for(int j = i + 1; j <= k; j++)
				got += arr[i].freq - arr[j].freq + 1;
			if(got <= m - a || arr[i].freq == 0)
				ans[arr[i].idx] = 2;
		}
		for(int i = k; i < n; i++)
		{
			//std::cout << arr[k - 1].freq - arr[i].freq + 1 << "\n";
			if(arr[k - 1].freq - arr[i].freq + 1 <= m - a)
				ans[arr[i].idx] = 2;
			else
				ans[arr[i].idx] = 3;
		}
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			ans[arr[i].idx] = arr[i].freq > 0 ? 1 : 2;
		}
	}
	for(int i = 0; i < n; i++)
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
}