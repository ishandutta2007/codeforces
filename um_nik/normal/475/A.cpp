#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string a[6] = {
    "+------------------------+",
    "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|",
    "|#.......................|",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
    "+------------------------+"
};
int n;
int x, y;

int main()
{
    x = 1;
    y = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[x][y] = 'O';
        x++;
        if (x == 3 && y != 1) x++;
        if (x == 5)
        {
            x = 1;
            y += 2;
        }
    }
    for (int i = 0; i < 6; i++)
        cout << a[i] << endl;
//  cin >> n;
    return 0;
}