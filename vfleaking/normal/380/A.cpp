#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxL = 100000;
const int MaxN = 100000;
const int MaxM = 100000;

int main()
{
	int m;
	int pre_n = 0;
	static int pre[MaxL * 2 + 1];

	static int type[MaxM + 1];
	static int qx[MaxM + 1], ql[MaxM + 1], qc[MaxM + 1];

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &type[i]);
		if (type[i] == 1)
		{
			scanf("%d", &qx[i]);
			if (pre_n < MaxL)
				pre[++pre_n] = qx[i];
		}
		else
		{
			scanf("%d %d", &ql[i], &qc[i]);
			for (int k = 0; k < qc[i] && pre_n < MaxL; k++)
				for (int j = 1; j <= ql[i]; j++)
					pre[++pre_n] = pre[j];
		}
	}

	int n;
	static s64 orz[MaxN + 1];
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> orz[i];

	int orzI = 1;

	s64 cur = 0;
	for (int i = 1; i <= m; i++)
	{
		if (type[i] == 1)
		{
			cur++;
			if (orzI <= n && orz[orzI] == cur)
				cout << qx[i] << " ", orzI++;
		}
		else
		{
			s64 le = cur + 1, ri = cur + ql[i] * qc[i];
			while (orzI <= n && le <= orz[orzI] && orz[orzI] <= ri)
				cout << pre[(orz[orzI] - le) % ql[i] + 1] << " ", orzI++;
			cur = ri;
		}
	}
	cout << endl;

	return 0;
}