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
const int MAXN = 2e5 + 10;

struct otr
{
    long long mi, ma;
    int num;
} mas[MAXN];

struct br
{
    long long len, num;
} tmp;

struct comp1
{
    bool operator() (const br& f, const br& s)
    {
        return (f.len == s.len ? f.num < s.num : f.len > s.len);
    }
};

bool comp(const otr& f, const otr& s)
{
    return (f.mi == s.mi ? f.ma == s.ma ? f.num > s.num : f.ma > s.ma : f.mi > s.mi);
}
set<br, comp1> brs;
set<br, comp1>::iterator it;

int main()
{
    tmp.num = 0;
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, ans[MAXN];
    long long l1, l2, r2, r1;
    bool f(0);
    cin >> n >> m;
    if(m < n - 1)
    {
        cout << "No";
        return 0;
    }
    cin >> l2 >> r2;
    for(int i(1); i < n; ++i)
    {
        l1 = l2;
        r1 = r2;
        cin >> l2 >> r2;
        mas[i - 1].mi = l2 - r1;
        mas[i - 1].ma = r2 - l1;
        mas[i - 1].num = i - 1;
    }
    --n;
    for(int i(0); i < m; ++i)
    {
        cin >> tmp.len;
        ++tmp.num;
        brs.insert(tmp);
    }
    sort(mas, mas + n, comp);
    tmp.num = -1;
    for(int i(0); i < n; ++i)
    {
        tmp.len = mas[i].ma;
        it = brs.lower_bound(tmp);
        if(it == brs.end() || it->len < mas[i].mi)
        {
            f = 1;
            break;
        }
        ans[mas[i].num] = it->num;
        brs.erase(it);
    }
    if(f)
    {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for(int i(0); i < n; ++i)
        cout << ans[i] << ' ';
    return 0;
}