#include <stdio.h>
#include <stdbool.h>

bool dp[105][105][105];
bool v[105][105][105];

bool ep[105][105][105];
bool y[105][105][105];

char dat[105];

// l, r     len    ?
bool E(int l, int r, int len);

// prerequisite: l - 1 r + 1 Y
bool D(int l, int r, int len)
{
	// l, r     len   ?
	if (r - l + 1 < len) return false;

	if (v[l][r][len] == false)
	{
		v[l][r][len] = true;

		if (r - l + 1 == len)
		{
			for (int i = l; i <= r; i++)
			{
				if (dat[i] == 'Y') return false;
			}
			return dp[l][r][len] = true;
		}

		for (int i = l; i <= r; i++)
		{
			if (dat[i] != 'N')
			{
				if (D(l, i - 1, len) && E(i + 1, r, len)) return dp[l][r][len] = true;
				if (E(l, i - 1, len) && D(i + 1, r, len)) return dp[l][r][len] = true;
			}
		}
	}

	return dp[l][r][len];
}

bool E(int l, int r, int len)
{
	if (r - l + 1 <= len) return true;
	if (len < 0) return false;
	if (y[l][r][len] == false)
	{
		y[l][r][len] = true;
		ep[l][r][len] = D(l, r, len) || E(l, r, len - 1);
	}
	return ep[l][r][len];
}

int main()
{
	int n, k;
	scanf("%d%d%s", &n, &k, dat);
	if (D(0, n - 1, k)) printf("YES\n");
	else printf("NO\n");
}