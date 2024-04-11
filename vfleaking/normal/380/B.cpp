#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 7000;
const int MaxM = 7000;
const int MaxL = 200000;

int main()
{
	int n, m;
	cin >> n >> m;

	static int preL[MaxL + 1];
	preL[1] = 1;
	for (int i = 2; i <= MaxL; i++)
		preL[i] = preL[i >> 1] + 1;

	static int qT[MaxM + 1], qV[MaxM + 1], qL[MaxM + 1], qR[MaxM + 1], qX[MaxM + 1];

	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &qT[i]);
		if (qT[i] == 1)
		{
			scanf("%d %d %d %d", &qV[i], &qL[i], &qR[i], &qX[i]);
		}
		else
		{
			scanf("%d %d", &qV[i], &qL[i]);
			static int vL[MaxN + 1], vR[MaxN + 1];

			vL[qV[i]] = vR[qV[i]] = qL[i];
			for (int v = qV[i] + 1; v <= n; v++)
			{
				vL[v] = vL[v - 1] + preL[vL[v - 1] - 1];
				vR[v] = vR[v - 1] + preL[vR[v - 1]];
			}

			int t_n = 0;
			static int t[MaxM];
			for (int j = 1; j < i; j++)
				if (qT[j] == 1 && qV[j] >= qV[i] && max(vL[qV[j]], qL[j]) <= min(vR[qV[j]], qR[j]))
					t[t_n++] = qX[j];
			sort(t, t + t_n);
			printf("%d\n", (int)(unique(t, t + t_n) - t));
		}
	}

	return 0;
}