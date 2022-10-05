#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, a[Maxn];
pair <long long, int> ans;
vector <pair <int, int> > tmp_Ve, Ve;
vector <int> Ve1, Ve2;
void work(void)
{
	Ve.push_back(make_pair(1, n));
	for (int x = 30; x >= 0; x--)
	{
		tmp_Ve.clear();
		long long val1 = 0, val2 = 0;
		for (vector <pair <int, int> > :: iterator it = Ve.begin(); it != Ve.end(); it++)
		{
			Ve1.clear(), Ve2.clear();
			int lt = it -> first, rt = it -> second;
			int cnt1 = 0, cnt2 = 0;
			for (int i = lt; i <= rt; i++)
			{
				if ((a[i] >> x) & 1) cnt1++, val2 += cnt2;
				else val1 += cnt1, cnt2++;
			}
		}
		if (val1 <= val2)
		{
			ans.first += val1;
			for (vector <pair <int, int> > :: iterator it = Ve.begin(); it != Ve.end(); it++)
			{
				Ve1.clear(), Ve2.clear();
				int lt = it -> first, rt = it -> second;
					for (int i = lt; i <= rt; i++)
						if ((a[i] >> x) & 1) Ve2.push_back(a[i]);
						else Ve1.push_back(a[i]);
				int pnt = lt - 1;
				for (vector <int> :: iterator it2 = Ve1.begin(); it2 != Ve1.end(); it2++)
					a[++pnt] = *it2;
				if (Ve1.size()) tmp_Ve.push_back(make_pair(lt, pnt));
				if (Ve2.size()) tmp_Ve.push_back(make_pair(pnt + 1, rt));
				for (vector <int> :: iterator it2 = Ve2.begin(); it2 != Ve2.end(); it2++)
					a[++pnt] = *it2;
			}
		}
		else
		{
			ans.first += val2;
			ans.second |= (1 << x);
			for (vector <pair <int, int> > :: iterator it = Ve.begin(); it != Ve.end(); it++)
			{
				Ve1.clear(), Ve2.clear();
				int lt = it -> first, rt = it -> second;
					for (int i = lt; i <= rt; i++)
						if ((a[i] >> x) & 1) Ve1.push_back(a[i]);
						else Ve2.push_back(a[i]);
				int pnt = lt - 1;
				for (vector <int> :: iterator it2 = Ve1.begin(); it2 != Ve1.end(); it2++)
					a[++pnt] = *it2;
				if (Ve1.size()) tmp_Ve.push_back(make_pair(lt, pnt));
				if (Ve2.size()) tmp_Ve.push_back(make_pair(pnt + 1, rt));
				for (vector <int> :: iterator it2 = Ve2.begin(); it2 != Ve2.end(); it2++)
					a[++pnt] = *it2;
			}
		}
		Ve = tmp_Ve;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	work();
	printf("%lld %d\n", ans.first, ans.second);
	return 0;
}