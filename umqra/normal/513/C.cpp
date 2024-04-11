#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int N = 6;
const int L = (int)1e4 + 100;
long double prob[2][N][L];
long double sumDp[2][N][L];
int l[N], r[N];
int indices[N];

void calc(int index, int n)
{
	prob[index][0][0] = 1.;
	for (int i = 0; i < n; i++)
	{
		int id = indices[i];
		sumDp[index][i][0] = prob[index][i][0];
		for (int s = 1; s < L; s++)
			sumDp[index][i][s] = sumDp[index][i][s - 1] + prob[index][i][s];
		long double len = r[id] - l[id] + 1;
		for (int s = l[id]; s <= r[id]; s++)
			prob[index][i + 1][s] += 1 / len * sumDp[index][i][s - 1];
		for (int s = 0; s < L; s++)
		{
			long double cntLessEq = 0;
			if (l[id] <= s)
			{
				if (r[id] > s)
					cntLessEq = s - l[id] + 1;
				else
					cntLessEq = r[id] - l[id] + 1;
			}
			prob[index][i + 1][s] += prob[index][i][s] * (long double)(cntLessEq) / len; 
		}
	}

}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];

	for (int i = 0; i < n; i++)
		indices[i] = i;
	calc(0, n);
	reverse(indices, indices + n);
	calc(1, n);

	long double ans = 0;
	for (int i = 0; i < n; i++)
	{
		long double len = r[i] - l[i] + 1;
		for (int s = 1; s < L; s++)
		{
			int cntGr = 0;
			int cntGrEq = 0;
			if (r[i] >= s)
			{
				if (l[i] <= s)
				{
					cntGr = r[i] - s;
					cntGrEq = r[i] - s + 1;
				}
				else
					cntGrEq = cntGr = r[i] - l[i] + 1;
			}
			long double p = prob[0][i][s];
			ans += s * p * sumDp[1][n - i - 1][s] * (long double)(cntGr) / len;
			p = prob[1][n - i - 1][s];
			ans += s * p * sumDp[0][i][s - 1] * (long double)(cntGrEq) / len;
		}
	}
	printf("%.11lf", (double)ans);

	return 0;
}