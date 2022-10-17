#include <iostream>
#include <cstdio>
#define maxn 200005
#define uint unsigned long long 
using namespace std;
int n, q, l1, l2, len;
int sum[maxn], cnt[maxn];
int pre[maxn], suf[maxn];
char s[maxn];
uint hash1[maxn], hash2[maxn], pow1[maxn], pow2[maxn], bas1 = 998244353, bas2 = 1e9 + 7;
void init()
{
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i <= n; i++) 
	{
		pow1[i] = pow1[i - 1] * bas1;
		pow2[i] = pow2[i - 1] * bas2;
	}
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1];
		if(s[i] == '1') sum[i]++;
	}
	pre[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if(s[i] == '0') pre[i] = i;
		else pre[i] = pre[i - 1];
	}
	suf[n + 1] = n + 1;
	for (int i = n; i >= 1; i--)
	{
		if(s[i] == '0') suf[i] = i;
		else suf[i] = suf[i + 1];
	}
}
void work()
{
	int p = 0;
	for (int i = 1; i <= n; i++)
	{
		if(s[i] == '0') 
		{
			cnt[i] = cnt[i - 1] + 1;
			hash1[i] = hash1[i - 1] * bas1;
			hash2[i] = hash2[i - 1] * bas2;
		}
		else
		{
			int last = pre[i];
			cnt[i] = cnt[last];
			if((i - last) & 1) 
			{
				hash1[i] = hash1[last] * bas1 + 1;
				hash2[i] = hash2[last] * bas2 + 1;
				cnt[i]++;
			}
			else 
			{
				hash1[i] = hash1[last];
				hash2[i] = hash2[last];
			} 
		}
	}
}
int check(int l, int r)
{
	int tl = suf[l];
	if(tl > r)
	{
		return (r - l + 1) & 1;
	}
	return cnt[r] - cnt[tl - 1] + ((tl - l) & 1);
}
uint calc1(int l, int r)
{
	int tl = suf[l];
	if(tl > r)
	{
		if((r - l + 1) & 1) return bas1;
		else return 0;
	}
	uint res = hash1[r] - hash1[tl - 1] * pow1[cnt[r] - cnt[tl - 1]];
	if((tl - l) & 1) res += pow1[cnt[r] - cnt[tl - 1]];
	return res;
}
uint calc2(int l, int r)
{
	int tl = suf[l];
	if(tl > r)
	{
		if((r - l + 1) & 1) return bas2;
		else return 0;
	}
	uint res = hash2[r] - hash2[tl - 1] * pow2[cnt[r] - cnt[tl - 1]];
	if((tl - l) & 1) res += pow2[cnt[r] - cnt[tl - 1]];
	return res;
}
int main()
{
	scanf("%d%s%d", &n, s + 1, &q);
	init();
	work();
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d%d", &l1, &l2, &len);
		if(calc1(l1, l1 + len - 1) != calc1(l2, l2 + len - 1) || calc2(l1, l1 + len - 1) != calc2(l2, l2 + len - 1) || check(l1, l1 + len - 1) != check(l2, l2 + len - 1) || sum[l1 + len - 1] - sum[l1 - 1] != sum[l2 + len - 1] - sum[l2 - 1])
		{
			printf("No\n");
		}
		else printf("Yes\n");
	}
	return 0;
}