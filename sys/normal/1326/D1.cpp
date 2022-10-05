#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2000005;
int T, maxi, R, pos, ans_pos, p[Maxn];
string str, ans_str, tmp;
void Manacher(string s)
{
	int siz = s.size();
	memset(p, 0, sizeof(int[siz]));
	R = pos = 0;
	for (int i = 1; i < siz; i++)
	{
		if (i < R) p[i] = min(p[2 * pos - i], R - i);
		else p[i] = 1;
		while (i - p[i] >= 1 && i + p[i] < siz && s[i - p[i]] == s[i + p[i]]) p[i]++;
		if (i + p[i] > R) R = i + p[i], pos = i;
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		maxi = 0;
		cin >> str;
		int siz = str.size(), pnt = 0;
		while (pnt < siz - 1 - pnt && str[pnt] == str[siz - 1 - pnt]) pnt++;
		tmp = "##"; 
		for (int i = pnt; i < siz - pnt; i++)
			tmp += str[i], tmp += '#';
		Manacher(tmp);
		int tmp_siz = tmp.size();
		for (int i = 1; i < tmp_siz; i++)
			if ((i - p[i] == 0 || i + p[i] == tmp_siz) && p[i] > maxi) maxi = p[i], ans_pos = i;
		ans_str = "";
		for (int i = 0; i < pnt; i++)
			ans_str += str[i];
		for (int i = ans_pos - p[ans_pos] + 1 + (tmp[ans_pos - p[ans_pos] + 1] == '#'); i <= ans_pos + p[ans_pos] - 1; i += 2)
			ans_str += tmp[i];
		for (int i = pnt - 1; i >= 0; i--)
			ans_str += str[i];
		cout << ans_str << endl;
	}
	return 0;
}