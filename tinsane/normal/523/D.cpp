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

struct comp
{
    bool operator() (long long& l, long long& r)
    {
        return (l > r);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    long long now(0), s, m;
    int n, k;
    priority_queue<long long, vector<long long>, comp> mas;
    cin >> n >> k;
    for (int i(0); i < n; ++i)
    {
        cin >> s >> m;
        now = MAX(now, s);
        if (mas.size() < k)
            mas.push(now + m);
        else
        {
            now = MAX(now, mas.top());
            mas.pop();
            mas.push(now + m);
        }
        cout << now + m << endl;
    }
    return 0;
}