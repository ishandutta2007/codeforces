#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define LL long long
using namespace std;

char s[10][100] = {
    "+------------------------+",
    "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|",
    "|#.......................|",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
    "+------------------------+"
};

int main () {
    int n;
    cin >> n;
    int x = 1, y = 1;
    while (n--) {
        s[x][y] = 'O';
        x++;
        if (x > 4) x = 1, y += 2;
        if (y > 1 && x == 3) x++;
    }
    for (int i = 0; i <= 5; i++) printf ("%s\n", s[i]);
}