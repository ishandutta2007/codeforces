#include <iostream>
#include <cstdio>
using namespace std;

const int N = (int)3e5 + 10;
int count[N];
char answer[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int zero_count = n;
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		count[x]++;
		if (count[x] == 1)
			zero_count--;
		if (zero_count == 0)
		{
			answer[i] = '1';
			for (int s = 0; s < n; s++)
			{
				count[s]--;
				if (count[s] == 0)
					zero_count++;
			}
		}
		else
			answer[i] = '0';
	}
	puts(answer);
	return 0;
}