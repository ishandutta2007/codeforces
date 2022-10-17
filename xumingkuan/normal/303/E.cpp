#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 82;
int n, a[MAXN][3];//l, r, r-l
int number[MAXN * 2], cnt = 0;
int mxnumn[MAXN], mxnumnl[MAXN];
double ans[MAXN], g[MAXN][MAXN][MAXN];//g[i][j]: j participants' score range < i-th's, k participants' = i-th's
double f[2][MAXN][MAXN];//f(l)[i&1][j][k]: score range l, first i participants, j of which < l, k of which = l, probability
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i][0], &a[i][1]);
		number[++cnt] = a[i][0];
		number[++cnt] = a[i][1];
		a[i][2] = a[i][1] - a[i][0];
	}
	sort(number + 1, number + cnt + 1);
	cnt = unique(number + 1, number + cnt + 1) - number - 1;
	for(int i = 1; i <= n; i++)//=> [l, r)
	{
		a[i][0] = find(number + 1, number + cnt + 1, a[i][0]) - number;
		a[i][1] = find(number + a[i][0], number + cnt + 1, a[i][1]) - number - 1;
	}
	memset(g, 0, sizeof(g));
	memset(mxnumn, 0, sizeof(mxnumn));
	memset(mxnumnl, 0, sizeof(mxnumnl));
	for(int l = 1; l <= cnt; l++)
	{
		memset(f, 0, sizeof(f));
		double (*f0)[MAXN] = f[0], (*f1)[MAXN] = f[1]; 
		f0[0][0] = 1;
		int nowlen = number[l + 1] - number[l];
		int numl = 0, numn = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i][1] < l)//pl = 1
			{
				numl++;
				continue;
			}
			else if(a[i][0] > l)//pg = 1
				continue;
			double pl = a[i][0] >= l ? 0 : (double)(number[l] - number[a[i][0]]) / a[i][2];//probability of: less
			double pe = (double)nowlen / a[i][2];//equal
			double pg = a[i][1] <= l ? 0 : (double)(number[a[i][1] + 1] - number[l + 1]) / a[i][2];//greater
			for(int j = numn; j >= 0; j--)
				for(int k = numn - j; k >= 0; k--)
				{
					double tmp = f0[j][k];
					f0[j + 1][k] += tmp * pl;
					f0[j][k + 1] += tmp * pe;
					f0[j][k] = tmp * pg;
				}
			numn++;
		}
		for(int i = 1; i <= n; i++)//reverse dp
		{
			if(a[i][1] < l || a[i][0] > l)
				continue;
			double pl = a[i][0] >= l ? 0 : (double)(number[l] - number[a[i][0]]) / a[i][2];
			double pe = (double)nowlen / a[i][2];
			double pg = a[i][0] > l ? 1 : (double)(number[a[i][1] + 1] - number[l + 1]) / a[i][2];
			if(pg > pl && pg > pe && pg > 0.35)
			{
				for(int j = 0; j <= numn - 1; j++)
					for(int k = 0; k <= numn - 1 - j; k++)
					{
						f1[j][k] = (f0[j][k] - (k ? f1[j][k - 1] * pe : 0) - (j ? f1[j - 1][k] * pl : 0)) / pg;
						g[i][j + numl][k] += f1[j][k] * pe;
					}
			}
			else if(pl > pe && pl > 0.35)
			{
				for(int j = numn - 1; j >= 0; j--)
					for(int k = 0; k <= numn - 1 - j; k++)
					{
						f1[j][k] = (f0[j + 1][k] - f1[j + 1][k] * pg - (k ? f1[j + 1][k - 1] * pe : 0)) / pl;
						g[i][j + numl][k] += f1[j][k] * pe;
					}
			}
			else
			{
				for(int j = 0; j <= numn - 1; j++)
					for(int k = numn - 1 - j; k >= 0; k--)
					{
						f1[j][k] = f0[j][k + 1] - f1[j][k + 1] * pg - (j ? f1[j - 1][k + 1] * pl : 0);
						g[i][j + numl][k] += f1[j][k];
						f1[j][k] /= pe;
					}
			}
			if(numn - 1 > mxnumn[i])
				mxnumn[i] = numn - 1;
			if(numn - 1 + numl > mxnumnl[i])
				mxnumnl[i] = numn - 1 + numl;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		memset(ans, 0, sizeof(ans));
		for(int j = 0; j <= mxnumnl[i]; j++)
		{
			int mxk = min(mxnumnl[i] - j, mxnumn[i]);
			for(int k = 0; k <= mxk; k++)
			{
				double now = g[i][j][k] / (k + 1);
				if(now < 1e-11)
					continue;
				for(int l = 0; l <= k; l++)
					ans[j + l] += now;
			}
		}
		for(int j = 0; j < n; j++)
			printf("%.7lf ", ans[j]);
		printf("\n");
	}
	return 0;
}