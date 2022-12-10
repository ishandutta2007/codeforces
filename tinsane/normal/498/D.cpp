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

#pragma comment(linker, "/STACK:167772160")

int str[500000][60];

void ins(int l, int r, int now, int val, int pos)
{
    if(r == l)
    {
        for(int i(0); i < 60; ++i)
            if(i % val)
                str[now][i] = 1;
            else
                str[now][i] = 2;
        return;
    }
    int mid = (r + l) / 2;
    if(mid < pos)
        ins(mid + 1, r, now * 2 + 1, val, pos);
    else
        ins(l, mid, now * 2, val, pos);
    for(int i(0); i < 60; ++i)
    {
        int t = str[now * 2][i];
        str[now][i] = t;
        str[now][i] += str[now * 2 + 1][(t + i) % 60];
    }
}

int get(int l, int r, int now, int L, int R, int T)
{
    if(L > R)
        return 0;
    if(l == L && r == R)
        return str[now][T];
    int del = get(l, (l + r) / 2, now * 2, L, MIN(R, (l + r) / 2), T);
    return del + get((l + r) / 2 + 1, r, now * 2 + 1, MAX(L, (l + r) / 2 + 1), R, (T + del) % 60);
}

int main()
{
    int n, q, x, y;
    char c;
    cin >> n;
    for(int i(0); i < n; ++i)
    {
        cin >> x;
        ins(0, n - 1, 1, x, i);
    }
    cin >> q;
    while(q--)
    {
        cin >> c >> x >> y;
        if(c == 'C')
            ins(0, n - 1, 1, y, x - 1);
        else
            cout << get(0, n - 1, 1, x - 1, y - 2, 0) << '\n';
    }
    return 0;
}