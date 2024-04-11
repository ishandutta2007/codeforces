#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 300005;
int n, pos[Maxn], cnt[3 * Maxn], tmp_maxi[Maxn];
long long ans;
void work(int lt, int rt)
{
	if (lt == rt)
	{
		ans++;
		return ;
	}
	int mid = (lt + rt) >> 1;
	work(lt, mid);
	work(mid + 1, rt);
	int pnt = mid, maxi = 0, mini = 0x3f3f3f3f;
	for (int i = mid; i >= lt; i--)
	{
		mini = min(mini, pos[i]), maxi = max(maxi, pos[i]);
		while (pnt < rt && pos[pnt + 1] >= mini && pos[pnt + 1] <= maxi)
			pnt++;
		if (maxi - mini + 1 <= pnt - i + 1 && i + (maxi - mini) > mid) ans++; 
	}
	pnt = mid + 1, maxi = 0, mini = 0x3f3f3f3f;
	for (int i = mid + 1; i <= rt; i++)
	{
		mini = min(mini, pos[i]), maxi = max(maxi, pos[i]);
		while (pnt > lt && pos[pnt - 1] >= mini && pos[pnt - 1] <= maxi)
			pnt--;
		if (maxi - mini + 1 <= i - pnt + 1 && i - (maxi - mini) <= mid) ans++;
	}
	maxi = tmp_maxi[mid] = 0, mini = 0x3f3f3f3f;
	for (int i = mid + 1; i <= rt; i++)
		tmp_maxi[i] = max(tmp_maxi[i - 1], pos[i]);
	int pnt1 = mid + 1, pnt2 = mid + 1;
	for (int i = mid; i >= lt; i--)
	{
		mini = min(mini, pos[i]);
		maxi = max(maxi, pos[i]);
		while (pnt1 <= rt && pos[pnt1] > mini)
			cnt[tmp_maxi[pnt1] - pnt1 + n]++, pnt1++;
		while (pnt2 < pnt1 && tmp_maxi[pnt2] < maxi)
			cnt[tmp_maxi[pnt2] - pnt2 + n]--, pnt2++;
		ans += cnt[mini - i + n];
	}
	while (pnt2 < pnt1)
		cnt[tmp_maxi[pnt2] - pnt2 + n]--, pnt2++;
	maxi = tmp_maxi[mid + 1] = 0, mini = 0x3f3f3f3f;
	for (int i = mid; i >= lt; i--)
		tmp_maxi[i] = max(tmp_maxi[i + 1], pos[i]);
	pnt1 = pnt2 = mid;
	for (int i = mid + 1; i <= rt; i++)
	{
		mini = min(mini, pos[i]);
		maxi = max(maxi, pos[i]);
		while (pnt1 >= lt && pos[pnt1] > mini)
			cnt[tmp_maxi[pnt1] + pnt1 + n]++, pnt1--;
		while (pnt2 > pnt1 && tmp_maxi[pnt2] < maxi)
			cnt[tmp_maxi[pnt2] + pnt2 + n]--, pnt2--;
		ans += cnt[mini + i + n];
	}
	while (pnt2 > pnt1)
		cnt[tmp_maxi[pnt2] + pnt2 + n]--, pnt2--;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		pos[x] = y;
	}
	work(1, n);
	printf("%lld", ans);
	return 0;
}