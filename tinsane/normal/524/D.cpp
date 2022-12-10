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
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

template <typename T>
inline T MIN(T lef, T ri)
{
    return (lef < ri ? lef : ri);
}

template <typename T>
inline T MAX(T lef, T ri)
{
    return (lef > ri ? lef : ri);
}

template <typename T>
inline T MOD(T val)
{
    return (val > 0 ? val : -val);
}

#pragma comment(linker, "/STACK:1677721600")

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, t, a, b, c, ans[20000], cnt(0);
    bool rec(0);
    char q;
    deque<int> mas;
    cin >> n >> m >> t;
    for(int i(0); i < n; ++i)
    {
        cin >> a >> q >> b >> q >> c;
        c += (a * 60 + b) * 60;
        for(; mas.size() && mas.front() + t <= c; mas.pop_front());
        if(mas.size() < m)
        {
            mas.push_back(c);
            ++cnt;
            ans[i] = cnt;
        }
        else
            mas.back() = c, ans[i] = ans[i - 1];
        rec |= mas.size() == m;
    }
    if(!rec)
    {
        cout << "No solution";
        return 0;
    }
    cout << cnt << '\n';
    for(int i(0); i < n; ++i)
        cout << ans[i] << '\n';
    return 0;
}