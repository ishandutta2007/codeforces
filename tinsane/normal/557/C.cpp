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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

struct leg
{
    int len, en;
} mas[MAXN];

bool comp(const leg& f, const leg& s)
{
    return f.len < s.len;
}
    
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, sum(0), res(MAXINT), bsum(0), tmp;
    multiset<int, std::greater<int>> win;
    multiset<int, std::greater<int>>::iterator it;
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i].len;
    for(int i(0); i < n; ++i)
        cin >> mas[i].en, sum += mas[i].en;
    sort(mas, mas + n, comp);
    for(int i(0), k(0); i < n; k = i)
    {
        for(sum -= mas[i++].en; i < n && mas[i].len == mas[i - 1].len; sum -= mas[i++].en);
        tmp = 0;
        it = win.begin();
        for(int j(1); it != win.end() && j < i - k; ++j, ++it)
            tmp += *it;
        res = min(res, sum + bsum - tmp);
        for(; k < i; ++k)
            bsum += mas[k].en, win.insert(mas[k].en);
    }
    cout << res;
    return 0;
}