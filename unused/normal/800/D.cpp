#include <bits/stdc++.h>
using namespace std;

int dat[1000005];
int dcnt[11][11][11][11][11][11];
int dsum[11][11][11][11][11][11];
int dssum[11][11][11][11][11][11];

int cntsum[11][11][11][11][11][11];
int sumsum[11][11][11][11][11][11];
int ssumsum[11][11][11][11][11][11];

constexpr int MOD = 1000000007;

int modpow[1000005], modinv[1000005];
int n;

template <typename T>
void addmod(int &t, T adde)
{
	t = (t + adde) % MOD;
}

template <typename T>
void submod(int &t, T adde)
{
	t = (t - adde + MOD) % MOD;
}

#define FOR(a,b,c) for (int a = b; a <= c; a++)

int cache[11][11][11][11][11][11];
bool v[11][11][11][11][11][11];

int calc(int a, int b, int c, int d, int e, int f)
{
	if (a >= 10 || b >= 10 || c >= 10 || d >= 10 || e >= 10 || f >= 10) return 0;
    if (v[a][b][c][d][e][f] == false)
    {
        v[a][b][c][d][e][f] = true;

        int total = cntsum[10 - a][10 - b][10 - c][10 - d][10 - e][10 - f], tsum = sumsum[10 - a][10 - b][10 - c][10 - d][10 - e][10 - f],
            tssum = ssumsum[10 - a][10 - b][10 - c][10 - d][10 - e][10 - f];

        if (total == 0) return 0;

        int mulx = (tsum * 1ll * tsum - tssum + MOD) % MOD * modinv[1] % MOD;

        return cache[a][b][c][d][e][f] = modpow[total - 1] * 1ll * (tssum + mulx) % MOD;
    }
    return cache[a][b][c][d][e][f];
}

int main()
{
    clock_t xxxxxxx = clock();

	modpow[0] = 1;
	for (int i = 1; i <= 1000000; i++) modpow[i] = (modpow[i - 1] << 1) % MOD;
	modinv[0] = 1;
	for (int i = 1; i <= 1000000; i++) modinv[i] = modinv[i - 1] * 1ll * 500000004 % MOD;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		dcnt[10 - dat[i] % 10][10 - dat[i] / 10 % 10][10 - dat[i] / 100 % 10][10 - dat[i] / 1000 % 10][10 - dat[i] / 10000 % 10][10 - dat[i] / 100000]++;
		addmod(dsum[10 - dat[i] % 10][10 - dat[i] / 10 % 10][10 - dat[i] / 100 % 10][10 - dat[i] / 1000 % 10][10 - dat[i] / 10000 % 10][10 - dat[i] / 100000], dat[i]);
		addmod(dssum[10 - dat[i] % 10][10 - dat[i] / 10 % 10][10 - dat[i] / 100 % 10][10 - dat[i] / 1000 % 10][10 - dat[i] / 10000 % 10][10 - dat[i] / 100000], dat[i] * 1ll * dat[i]);
	}

#define FOR(a,b,c) for (int a = b; a <= c; a++)

	FOR(a, 1, 10) FOR(b, 1, 10) FOR(c, 1, 10) FOR(d, 1, 10) FOR(e, 1, 10) FOR(f, 1, 10)
	{
		cntsum[a][b][c][d][e][f] = dcnt[a][b][c][d][e][f];
		sumsum[a][b][c][d][e][f] = dsum[a][b][c][d][e][f];
		ssumsum[a][b][c][d][e][f] = dssum[a][b][c][d][e][f];

		FOR(da, -1, 0) FOR(db, -1, 0) FOR(dc, -1, 0) FOR(dd, -1, 0) FOR(de, -1, 0) FOR(df, -1, 0)
		{
			if (da == 0 && db == 0 && dc == 0 && dd == 0 && de == 0 && df == 0) continue;
			if (!(da^db^dc^dd^de^df))
			{
				cntsum[a][b][c][d][e][f] -= cntsum[a + da][b + db][c + dc][d + dd][e + de][f + df];
				submod(sumsum[a][b][c][d][e][f], sumsum[a + da][b + db][c + dc][d + dd][e + de][f + df]);
				submod(ssumsum[a][b][c][d][e][f], ssumsum[a + da][b + db][c + dc][d + dd][e + de][f + df]);
			}
			else
			{
				cntsum[a][b][c][d][e][f] += cntsum[a + da][b + db][c + dc][d + dd][e + de][f + df];
				addmod(sumsum[a][b][c][d][e][f], sumsum[a + da][b + db][c + dc][d + dd][e + de][f + df]);
				addmod(ssumsum[a][b][c][d][e][f], ssumsum[a + da][b + db][c + dc][d + dd][e + de][f + df]);
			}
		}
	}

	long long ans = 0;

	for (int i = 1; i <= 999999; i++)
	{
		int a, b, c, d, e, f;
		tie(a, b, c, d, e, f) = make_tuple(i % 10, i / 10 % 10, i / 100 % 10, i / 1000 % 10, i / 10000 % 10, i / 100000 % 10);
		int total = 0;

		FOR(da, 0, 1) FOR(db, 0, 1) FOR(dc, 0, 1) FOR(dd, 0, 1) FOR(de, 0, 1) FOR(df, 0, 1)
		{
			if (da^db^dc^dd^de^df)
			{
				submod(total, calc(a + da, b + db, c + dc, d + dd, e + de, f + df));
			}
			else
			{
				addmod(total, calc(a + da, b + db, c + dc, d + dd, e + de, f + df));
			}
		}

		ans ^= total * 1ll * i;
	}

	printf("%lld\n", ans);
}