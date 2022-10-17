#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
class Stu
{
public:
	int id, sum;
	void read(int i)
	{
		id = i;
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		sum = a + b + c + d;
	}
	bool operator <(const Stu &b) const
	{
		return sum == b.sum ? id < b.id : sum > b.sum;
	}
}a[1010];
int n;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		a[i].read(i);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		if(a[i].id == 1)
		{
			printf("%d\n", i);
			break;
		}
	return 0;
}