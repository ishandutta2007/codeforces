#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxPL = 1000000;
const int MaxKL = 2000;
const int MaxSL = 200;

int main()
{
	static char ps[MaxPL + 2];
	int pl;
	static char s[MaxSL + 2];
	int sl;
	int kl;

	fgets(ps, sizeof(ps), stdin), ps[pl = strlen(ps) - 1] = '\0';
	fgets(s, sizeof(s), stdin), s[sl = strlen(s) - 1] = '\0';
	scanf("%d", &kl);

	string res = "0";
	for (int t = 1; t <= sl; t++)
		if ((pl / kl) * t <= sl && sl <= (pl / kl + 1) * t)
		{
			static string a[MaxKL + 1], b[MaxSL + 1];
			for (int i = 0; i < kl; i++)
			{
				a[i] = "";
				for (int k = i; k < pl; k += kl)
					a[i] += ps[k];
			}
			for (int i = 0; i < t; i++)
			{
				b[i] = "";
				for (int k = i; k < sl; k += t)
					b[i] += s[k];
			}

			string cur(kl, '0');
			int p = kl - 1;
			for (int i = t - 1; i >= 0; i--)
			{
				while (p >= 0 && a[p] != b[i])
					p--;
				if (p < 0)
				{
					cur = "0";
					break;
				}
				cur[p--] = '1';
			}
			if (cur != "0" && (res == "0" || cur < res))
				res = cur;
		}

	cout << res << endl;

	return 0;
}