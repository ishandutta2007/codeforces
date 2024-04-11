#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 52;
const int NCardTypes = 52;

inline int getCard()
{
	char a, b;
	cin >> a >> b;
	int res = 0;

	if ('2' <= a && a <= '9')
		res += (a - '2') * 4;
	else if (a == 'T')
		res += 8 * 4;
	else if (a == 'J')
		res += 9 * 4;
	else if (a == 'Q')
		res += 10 * 4;
	else if (a == 'K')
		res += 11 * 4;
	else if (a == 'A')
		res += 12 * 4;

	if (b == 'S')
		res += 0;
	else if (b == 'D')
		res += 1;
	else if (b == 'H')
		res += 2;
	else if (b == 'C')
		res += 3;

	return res;
}

inline bool isGood(const int &a, const int &b)
{
	return a % 4 == b % 4 || a / 4 == b / 4;
}

int main()
{
	int n;
	int cards[MaxN + 1];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cards[i] = getCard();

	if (n == 1)
	{
		cout << "YES" << endl;
		return 0;
	}
	else if (n == 2)
	{
		if (isGood(cards[1], cards[2]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}


	static bool f[MaxN + 1][NCardTypes][NCardTypes][NCardTypes];
	for (int i = 0; i < NCardTypes; i++)
		for (int j = 0; j < NCardTypes; j++)
			for (int k = 0; k < NCardTypes; k++)
			{
				if (isGood(j, k) && isGood(k, i))
					f[1][i][j][k] = true;
				else
					f[1][i][j][k] = false;
			}

	for (int index = 2; index + 2 <= n; index++)
		for (int i = 0; i < NCardTypes; i++)
			for (int j = 0; j < NCardTypes; j++)
				for (int k = 0; k < NCardTypes; k++)
				{
					f[index][i][j][k] = false;
					if (isGood(j, k))
						f[index][i][j][k] |= f[index - 1][cards[index - 1]][i][k];
					if (isGood(k, cards[index - 1]))
						f[index][i][j][k] |= f[index - 1][k][i][j];
				}

	if (f[n - 2][cards[n - 2]][cards[n - 1]][cards[n]])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}