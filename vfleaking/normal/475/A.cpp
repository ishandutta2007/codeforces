#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char a[][50] = {
		"+------------------------+",
		"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
		"|#.#.#.#.#.#.#.#.#.#.#.|.|",
		"|#.......................|",
		"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
		"+------------------------+"
	};

	int n;
	cin >> n;
	for (int j = 0; j < 26 && n > 0; j++)
		for (int i = 1; i <= 4 && n > 0; i++)
			if (a[i][j] == '#')
				a[i][j] = 'O', n--;

	for (int i = 0; i < 6; i++)
		cout << a[i] << endl;

	return 0;
}