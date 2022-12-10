#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#pragma comment(linker, "/STACK:1677721600")

const long long MAXLL = 2e18;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;

template <typename T>
T MOD(T a)
{
    return (a > 0 ? a : -a);
}

template <typename T>
T MAX(T a, T b)
{
    return (a > b ? a : b);
}

template <typename T>
T MIN(T a, T b)
{
    return (a > b ? b : a);
}
const double TL = 2;    // 2 sec

inline bool isTL()
{
    static bool is(0);
    static int cou(0);
    if (++cou > 1000)
    {
        cou = 0;
        is |= clock() > (TL - 0.08) * CLOCKS_PER_SEC;
    }
    return is;
}
int h, w;
string mas[400], tmp[400];

void rotate()
{
    for (int i(0); i < w; ++i)
        tmp[i].resize(h);
    for (int i(0); i < w; ++i)
    for (int j(h - 1); j >= 0; --j)
        tmp[i][h - 1 - j] = mas[j][i];
    for (int i(0); i < w; ++i)
        mas[i] = tmp[i];
}

void sim()
{
    for (int i(0); i < w; ++i)
        reverse(mas[i].begin(), mas[i].end());
}

void increase()
{
    for (int i(0); i < 2 * w; ++i)
        tmp[i].resize(2 * h);
    for (int i(0); i < w; ++i)
    for (int j(0); j < h; ++j)
        tmp[i * 2][j * 2] = tmp[i * 2 + 1][j * 2] = tmp[i * 2][j * 2 + 1] = tmp[i * 2 + 1][j * 2 + 1] = mas[i][j];
    for (int i(0); i < 2 * w; ++i)
        mas[i] = tmp[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> w >> h;
    for (int i(0); i < h; ++i)
        cin >> mas[i];
    rotate();
    sim();
    increase();
    for (int i(0); i < w * 2; ++i)
        cout << mas[i] << endl;
    return 0;
}