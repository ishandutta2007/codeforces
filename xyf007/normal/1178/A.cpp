#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct party
{
	int sum, id;
	bool operator<(const party a)const
	{
		return sum < a.sum;
	}
} a[101];
int n;
vector<int> ans;
int main()
{
	scanf("%d", &n);
	int sum = 0, temp = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].sum);
		sum += a[i].sum;
		a[i].id = i;
	}
	sort(a + 2, a + n + 1);
	ans.push_back(1);
	temp = a[1].sum;
	for (int i = 2; i <= n; i++)
	{
		if(a[i].sum * 2 > a[1].sum)
		{
			break;
		}
		ans.push_back(a[i].id);
		temp += a[i].sum;
	}
	if(temp < (sum / 2 + 1))
	{
		printf("0");
		return 0;
	}
	printf("%d\n", (int)ans.size());
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		printf("%d ", *it);
	}
	return 0;
}