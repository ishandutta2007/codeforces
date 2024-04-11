#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
bool type = true;
int n, ct;
string str;
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
//	freopen("C.in", "r", stdin);
	scanf("%d", &n); 
	printf("? %d %d\n", 1, n);
	fflush(stdout);
	for (int i = 1; i <= n * (n + 1) / 2; i++)
	{
		ans tmp;
		memset(tmp.cnt, 0, sizeof(tmp.cnt));
		cin >> str;
		if (n == 1)
		{
			cout << "! " << str << endl;
			return 0;
		}
		int siz = str.size();
		for (int j = 0; j < siz; j++)
			tmp.cnt[str[j] - 'a' + 1]++;
		Ma[tmp]++;
	}
	printf("? %d %d\n", 2, n);
	fflush(stdout);
	for (int i = 1; i <= n * (n - 1) / 2; i++)
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
	sort(res + 1, res + 1 + n);
	str = "";
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 26; j++)
			if (res[i - 1].cnt[j] != res[i].cnt[j])
				str += j + 'a' - 1;
	cout << "! " << str << endl;
	return 0;
}