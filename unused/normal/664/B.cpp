#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> op;
int p, m;

vector<int> ps, ms;

int main()
{
	p = 1;
	for (;;)
	{
		char ch;
		scanf(" %*c %c", &ch);
		if (ch == '=') break;
		op.push_back(ch);
		if (ch == '+') p++;
		else m++;
	}
	int n;
	scanf("%d", &n);

	// : p * n - m
	// : p - m * n
	if (p - m * n <= n && n <= p * n - m)
	{
		printf("Possible\n");
		ps.resize(p, 1);
		ms.resize(m, 1);
		int remain = (p - m) - n;

		if (remain < 0)
		{
			for (int i = 0; i < p && remain; i++)
			{
				int adde = min(n - 1, -remain);
				ps[i] += adde;
				remain += adde;
			}
		}
		else
		{
			for (int i = 0; i < m && remain; i++)
			{
				int adde = min(n - 1, remain);
				ms[i] += adde;
				remain -= adde;
			}
		}

		printf("%d ", ps[0]);

		for (int p1 = 1, m1 = 0, j = 0; j < op.size(); j++)
		{
			printf("%c ", op[j]);
			if (op[j] == '-') printf("%d ", ms[m1++]);
			else printf("%d ", ps[p1++]);
		}
		printf("= %d\n", n);
	}
	else
	{
		printf("Impossible\n");
	}
}