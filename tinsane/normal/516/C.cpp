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

struct node
{
    int lm, rm;
};
long long d[200001], h[200001];

node doo[1000000];

void merge(node& wh, node& l, node& r)
{
    if(MOD(d[r.lm] - d[l.lm]) + h[r.lm] * 2 > h[l.lm] * 2)
        wh.lm = r.lm;
    else
        wh.lm = l.lm;
    if(MOD(d[r.rm] - d[l.rm]) + h[l.rm] * 2 > h[r.rm] * 2)
        wh.rm = l.rm;
    else
        wh.rm = r.rm;
}

void build(int l, int r, int i)
{
    if(l == r)
    {
        doo[i].lm = doo[i].rm = l;
        return;
    }
    build(l, (l + r) / 2, i * 2);
    build((l + r) / 2 + 1, r, i * 2 + 1);
    merge(doo[i], doo[i * 2], doo[i * 2 + 1]);
}

node get(int a, int b, int i, int l, int r)
{
    node win;
    if(a == l && b == r)
        return doo[i];
    if(b <= (l + r) / 2)
        win = get(a, b, i * 2, l, (l + r) / 2);
    else if(a >= (l + r) / 2 + 1)
        win = get(a, b, i * 2 + 1, (l + r) / 2 + 1, r);
    else
        merge(win, get(a, (l + r) / 2, i * 2, l, (l + r) / 2), get((l + r) / 2 + 1, b, i * 2 + 1, (l + r) / 2 + 1, r));
    return win;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, a, b;
    node tmp;
    h[200000] = d[200000] = -1;
    cin >> n >> m;
    d[0] = 0;
    for(int i(0); i < n; ++i)
    {
        cin >> d[i + 1];
        d[i + n + 1] = d[i + 1];
    }
    for(int i(1); i < n * 2; ++i)
        d[i] += d[i - 1]; 
    for(int i(0); i < n; ++i)
    {
        cin >> h[i];
        h[i + n] = h[i];
    }
    build(0, n * 2 - 1, 1);
    while(m--)
    {
        cin >> a >> b;
        --a, --b;
        if(a > b)
            tmp = get(b + 1, a - 1, 1, 0, n * 2 - 1);
        else
            tmp = get(b + 1, n + a - 1, 1, 0, n * 2 - 1);
        if(tmp.lm != tmp.rm)
            cout << (h[tmp.rm] + h[tmp.lm]) * 2 + MOD(d[tmp.rm] - d[tmp.lm]) << '\n';
        else
        {
            node tmp1, tmp2;
            if(a > b)
            {
                if(tmp.lm == b + 1)
                {
                    tmp2 = get(tmp.lm + 1, a - 1, 1, 0, n * 2 - 1);
                    cout << (h[tmp2.lm] + h[tmp.lm]) * 2 + MOD(d[tmp2.lm] - d[tmp.lm]) << '\n';
                    continue;
                }
                else if(tmp.lm == a - 1)
                {
                    tmp1 = get(b + 1, tmp.lm - 1, 1, 0, n * 2 - 1);
                    cout << (h[tmp.rm] + h[tmp1.rm]) * 2 + MOD(d[tmp.rm] - d[tmp1.rm]) << '\n';
                    continue;

                }
                tmp1 = get(b + 1, tmp.lm - 1, 1, 0, n * 2 - 1);
                tmp2 = get(tmp.lm + 1, a - 1, 1, 0, n * 2 - 1);
                cout << MAX((h[tmp.rm] + h[tmp1.rm]) * 2 + MOD(d[tmp.rm] - d[tmp1.rm]), (h[tmp.rm] + h[tmp2.lm]) * 2 + MOD(d[tmp.rm] - d[tmp2.lm])) << '\n';
            }
            else
            {
                if(tmp.lm == b + 1)
                {
                    tmp2 = get(tmp.lm + 1, n + a - 1, 1, 0, n * 2 - 1);
                    cout << (h[tmp2.lm] + h[tmp.lm]) * 2 + MOD(d[tmp2.lm] - d[tmp.lm]) << '\n';
                    continue;
                }
                else if(tmp.lm == n + a - 1)
                {
                    tmp1 = get(b + 1, tmp.lm - 1, 1, 0, n * 2 - 1);
                    cout << (h[tmp.rm] + h[tmp1.rm]) * 2 + MOD(d[tmp.rm] - d[tmp1.rm]) << '\n';
                    continue;

                }
                tmp1 = get(b + 1, tmp.lm - 1, 1, 0, n * 2 - 1);
                tmp2 = get(tmp.lm + 1, n + a - 1, 1, 0, n * 2 - 1);
                cout << MAX((h[tmp.rm] + h[tmp1.rm]) * 2 + MOD(d[tmp.rm] - d[tmp1.rm]), (h[tmp.rm] + h[tmp2.lm]) * 2 + MOD(d[tmp.rm] - d[tmp2.lm])) << '\n';
            }
        }
    }
    return 0;
}