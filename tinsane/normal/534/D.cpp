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
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 2e5 + 10;

struct Stud
{
    int cnt, num;
} tmp;

int n, cnt(0), ans[MAXN], asi(0);

struct comp
{
    bool operator() (Stud f, Stud s)
    {
        return (f.cnt == s.cnt ? f.num < s.num : f.cnt < s.cnt);
    }
};

set<Stud, comp> mas;
set<Stud, comp>::iterator it, it1;

void myer()
{
    it1 = it++;
    mas.erase(it1);
}

void init()
{
    cin >> n;
    for(int i(1); i <= n; ++i)
        cin >> tmp.cnt, tmp.num = i, mas.insert(tmp);
}

void solve()
{
    while(mas.size() && cnt >= 0)
    {
        tmp.cnt = cnt;
        tmp.num = 0;
        it = mas.lower_bound(tmp);
        if(it == mas.end() || it->cnt > cnt)
        {
            cnt -= 3;
            continue;
        }
        ++cnt;
        ans[asi++] = it->num;
        mas.erase(it);
    }
}

void output()
{
    if(mas.size())
        cout << "Impossible";
    else
    {
        cout << "Possible\n";
        for(int i(0); i < n; ++i)
            cout << ans[i] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}