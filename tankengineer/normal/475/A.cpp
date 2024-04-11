#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char map[6][100] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int y = 0; y < 100 && !flag; ++y) {
            for (int x = 0; x < 6 && !flag; ++x) {
                if (map[x][y] == '#') {
                    map[x][y] = 'O';
                    flag = true;
                }
            }
        }
    }
    for (int i = 0; i < 6; ++i) {
        puts(map[i]);
    }
    return 0;
}