#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 105 * 105;
pair <int, int> P[Maxn];
bool type = true;
int n, ct;
string S, str, Tmp;
struct ans
{
	int cnt[27];
	bool operator < (const ans &tmp) const
	{
		if (type)
		{
			for (int i = 1; i <= 26; i++)
				if (cnt[i] != tmp.cnt[i]) return cnt[i] < tmp.cnt[i];
			return false;
		}
		else
		{
			int tmp1 = 0;
			for (int i = 1; i <= 26; i++)
				tmp1 += cnt[i] - tmp.cnt[i];
			return tmp1 < 0;
		}
	}
}res[Maxn];
map <ans, int> Ma;
int main()
{
	scanf("%d", &n);
	if (n <= 3)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("? %d %d\n", i, i);
			fflush(stdout);
			cin >> str;
			S += str;
		}
		cout << "! " << S << endl;
		return 0;
	}
	int limit1 = ceil(n * 0.66667); 
	printf("? %d %d\n", 1, limit1);
	fflush(stdout);
	for (int i = 1; i <= limit1 * (limit1 + 1) / 2; i++)
	{
		ans tmp;
		memset(tmp.cnt, 0, sizeof(tmp.cnt));
		cin >> str;
		int siz = str.size();
		for (int j = 0; j < siz; j++)
			tmp.cnt[str[j] - 'a' + 1]++;
		Ma[tmp]++;
	}
	printf("? %d %d\n", 2, limit1);
	fflush(stdout);
	for (int i = 1; i <= limit1 * (limit1 - 1) / 2; i++)
	{
		ans tmp;
		memset(tmp.cnt, 0, sizeof(tmp.cnt));
		cin >> str;
		int siz = str.size();
		for (int j = 0; j < siz; j++)
			tmp.cnt[str[j] - 'a' + 1]++;
		Ma[tmp]--;
		if (!Ma[tmp]) Ma.erase(tmp);
	}
	for (map <ans, int> :: iterator it = Ma.begin(); it != Ma.end(); it++)
		res[++ct] = it -> first;
	type = false;
	sort(res + 1, res + 1 + limit1);
	str = "";
	for (int i = 1; i <= limit1; i++)
		for (int j = 1; j <= 26; j++)
			if (res[i - 1].cnt[j] != res[i].cnt[j])
				S += j + 'a' - 1;
	int limit2 = n - 2 * (n - limit1) + 1;
	ct = 0;
	printf("? %d %d\n", limit2, n);
	fflush(stdout); 
	for (int i = 1; i <= (n - limit2 + 1) * (n - limit2 + 2) / 2; i++)
	{
		ans tmp;
		memset(tmp.cnt, 0, sizeof(tmp.cnt));
		cin >> str;
		int siz = str.size();
		for (int j = 0; j < siz; j++)
			tmp.cnt[str[j] - 'a' + 1]++;
		res[++ct] = tmp;
	}
	sort(res + 1, res + 1 + ct);
	reverse(res + 1, res + 1 + ct); 
	int Cnt = 1;
	ans now;
	memset(now.cnt, 0, sizeof(now.cnt));
	memset(res[ct + 1].cnt, 0, sizeof(res[ct + 1].cnt));
	for (int i = 2; i <= ct + 1; i++)
	{
		if (i != 2 && res[i] < res[i - 1])
		{
			Cnt++;
			for (int j = 1; j <= Cnt - 2; j++)
				now.cnt[P[j].first] -= j, now.cnt[P[j].second] -= j;
			P[Cnt - 1].first = S[limit2 + Cnt - 3] - 'a' + 1;
			for (int j = 1; j <= 26; j++)
				now.cnt[j] %= Cnt;
			now.cnt[S[limit2 + Cnt - 3] - 'a' + 1] -= Cnt - 1;
			for (int j = 1; j <= 26; j++)
				if (now.cnt[j])
					P[Cnt - 1].second = j, Tmp += j + 'a' - 1;
			memset(now.cnt, 0, sizeof(now.cnt));
		}
		for (int j = 1; j <= 26; j++)
			now.cnt[j] += res[i].cnt[j]; 
	}
	int siz = S.size();
	for (int j = 1; j <= n - siz; j++)
		S += Tmp[n - siz - j];
	cout << "! " << S << endl;
	return 0;
}