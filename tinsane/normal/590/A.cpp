#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

#define mk make_pair

typedef pair<int, int> pii;

//8739

const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 5e5 + 10;

int n, res(0);
char mas[MAXN], nmas[MAXN];

void init()
{
    cin >> n;
    for(int i(1); i <= n; ++i)
        cin >> mas[i];
    mas[0] = mas[1];
    nmas[0] = mas[0] + 2;
    mas[n + 1] = mas[n];
    nmas[n + 1] = mas[n + 1] + 2;
    n += 2;
}

void solve()
{
    for(int i(1); i < n - 1; ++i)
    {
        if (mas[i] == mas[i - 1] || mas[i] == mas[i + 1])
            nmas[i] = mas[i] + 2;
        else
            nmas[i] = mas[i];
    }
    for(int i(0); i < n; ++i)
    if(nmas[i] < '2')
    {
        int j, len;
        for(j = i; nmas[j] < '2'; ++j);
        len = j - i;
        if (len & 1)
            for(int k(i); k < j; ++k)
                nmas[k] = nmas[j];
        else
        {
            for(int k(i); k < (i + j) / 2; ++k)
                nmas[k] = nmas[i - 1];
            for(int k((i + j) / 2); k < j; ++k)
                nmas[k] = nmas[j];

        }
        res = max(res, (len + 1) / 2);
        i = j;
    }
}

void output()
{
    cout << res << '\n';
    for(int i(1); i < n - 1; ++i)
        cout << (char) (nmas[i] - 2) << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
}