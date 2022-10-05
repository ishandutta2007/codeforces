#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 205;
string pre1, pre2, suf, now, str[Maxn];
int n, m;
long long k, cnt[Maxn];
namespace brute_forces
{
	int N, M, first[1000005], second[1000005], buc[1000005], sa[1000005];
	void radix_sort(int first[], int second[])
	{
		for (int i = 0; i <= M; i++) buc[i] = 0;
		for (int i = 0; i < N; i++) buc[first[second[i]]]++;
		for (int i = 1; i <= M; i++) buc[i] += buc[i - 1];
		for (int i = N - 1; i >= 0; i--) sa[--buc[first[second[i]]]] = second[i];
	}
	void work(void)
	{
		N = str[n].size();
		M = 2;
		for (int i = 0; i < N; i++)
			first[i] = str[n][i] - '0', second[i] = i, sa[i] = 0;
		radix_sort(first, second);
		for (int w = 1; w <= N; w <<= 1)
		{
			int cnt = 0;
			for (int i = N - w; i < N; i++)
				second[cnt++] = i;
			for (int i = 0; i < N; i++)
				if (sa[i] >= w) second[cnt++] = sa[i] - w;
			radix_sort(first, second);
			swap(first, second);
			cnt = 0;
			first[sa[0]] = cnt++;
			for (int i = 1; i < N; i++)
				first[sa[i]] = (sa[i] + w < N && sa[i - 1] + w < N && second[sa[i]] == second[sa[i - 1]] && second[sa[i] + w] == second[sa[i - 1] + w]) ? cnt - 1 : cnt++;
			if (cnt >= N) break;
			M = cnt;
		}
	}
}
int path(string x, string y, string z)
{
	int tmp_ans = 0, sizZ = z.size(), sizX = x.size(), sizY = y.size();
	for (int i = 0; i < sizX; i++)
		if (sizX - i < sizZ && sizX - i + sizY >= sizZ)
		{
			for (int j = i; j < sizX; j++)
				if (x[j] != z[j - i])
				{
					tmp_ans += x[j] < z[j - i];
					goto END;
				}
			for (int j = 0; j < sizZ - sizX + i; j++)
				if (y[j] != z[j + sizX - i])
				{
					tmp_ans += y[j] < z[j + sizX - i];
					goto END;
				}
			END:;
		}
	return tmp_ans;
}
long long cal(void)
{
	pre1 = pre2 = suf = "";
	int s = now.size();
	if (now.size() == 1) cnt[0] = 1;
	else cnt[0] = 0;
	if (now.size() == 2) pre2 = "0", pre1 = suf = "1";
	if (now.size() == 3) pre1 = suf = "1";
	for (int i = 2; i <= n; i++)
	{
		cnt[i] = cnt[i - 1] + cnt[i - 2];
		if (cnt[i] >= 1e18) return 1e18;
		if (i >= 15 || str[i - 2].size() >= now.size())
		{
			if (i & 1)
				cnt[i] += path(suf, pre2, now);
			else cnt[i] += path(suf, pre1, now);
		}
		else cnt[i] += path(str[i - 2], str[i - 1], now);
		if (i & 1)
		{
			if ((int)pre1.size() == s) continue;
			int siz = str[i].size();
			suf = pre1 = "";
			for (int j = 0; j < min(s, (int)str[i].size()); j++)
				pre1 += str[i][j];
			for (int j = max(0, siz - s); j < siz; j++)
				suf += str[i][j];
		}
		else
		{
			if ((int)pre2.size() == s) continue;
			pre2 = "";
			for (int j = 0; j < min(s, (int)str[i].size()); j++)
				pre2 += str[i][j];
		}
	}
	return cnt[n];
}
int main()
{
	scanf("%d%lld%d", &n, &k, &m);
	str[0] = "0", str[1] = "1";
	for (int i = 2; i <= 27; i++)
		str[i] = str[i - 2] + str[i - 1];
	if (n <= 27)
	{
		brute_forces::work();
		int siz = min((int)str[n].size() - brute_forces::sa[k - 1], m);
		for (int i = 0; i < siz; i++)
			putchar(str[n][brute_forces::sa[k - 1] + i]);
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		string tmp = now;
		now += '1';
		long long ans_now = cal();
		for (int j = 1; j < suf.size(); j++)
		{
			string tmpstr = "";
			for (int k = j; k < suf.size(); k++)
				tmpstr += suf[k];
			if (tmpstr < now) ans_now++;
		}
		if (ans_now == k - 1 && now == suf)
		{
			cout << now;
			return 0;
		}
		if (ans_now > k - 1) now = tmp, now += '0';
	}
	cout << now;
	return 0;
}