#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 5e4 + 10;
    int n, res[200001], mas[200001], cnt(0), i;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    ++n;
    cin >> mas[1];

    for(i = 2; i < n; ++i)
        cin >> mas[i], cnt += (mas[i] < mas[1]), res[i - 1] = cnt, res[1] += (mas[i] < mas[i - 1]);

    if(mas[2] < mas[1])
        --res[1];

    for(i = 2; i * i + i + 2 < n; ++i)
        for(int j(i + 2); j < n; ++j)
            res[i] += (mas[j] < mas[(j + i - 2) / i]);

    for(int j(2); j < n; ++j)
    {
        int f = (j - 1) * i + 2, l = min(f + i, n), nf, nl;
        cnt = 0;
        if(f >= n)
            break;
        for(int k(f); k < l; ++k)
            cnt += (mas[k] < mas[j]);
        res[i] += cnt;
        for(int t(1); f < n; ++t)
        {
            nf = f + j - 1;
            if(nf >= n)
                break;
            nl = min(l + nf - f, n - 1);
            for(;f < nf; ++f)
                cnt -= (mas[f] < mas[j]);
            for(;l <= nl; ++l)
                cnt += (mas[l] < mas[j]);
            res[i + t] += cnt;
        }
    }
    for(int i(1); i < n - 1; ++i)
        cout << res[i] << ' ';
    return 0;
}