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

int main()
{
    ios_base::sync_with_stdio(0);
    int n, T, m, ti;
    double mas[200000];
    double c, mean[200001], real[200001];
    stack<int> a;
    cin >> n >> T >> c;
    mean[0] = 0;
    real[0] = 0;
    for (int i(0); i < T; ++i)
    {
        cin >> mas[i];
        mean[i + 1] = (mean[i] + mas[i] / T) / c;
        real[i + 1] = real[i] + mas[i];
    }
    for (int i(T); i < n; ++i)
    {
        cin >> mas[i];
        mean[i + 1] = (mean[i] + mas[i] / T) / c;
        real[i + 1] = real[i] + mas[i] - mas[i - T];
    }
    for (int i(0); i <= n; ++i)
        real[i] /= T;
    cin >> m;
    cout << setprecision(6) << fixed;
    for (int i(0); i < m; ++i)
    {
        cin >> ti;
        cout << real[ti] << ' ' << mean[ti] << ' ' << MOD(mean[ti] - real[ti]) / real[ti] << endl;
    }
    return 0;
}