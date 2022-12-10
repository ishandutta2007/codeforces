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

struct que
{
    char c;
    int pos, num;
} mas[MAXN];

int n, q, x, y, useg[MAXN * 5], lseg[MAXN * 5], unum[MAXN], lnum[MAXN], usi(0), lsi(0);

bool comp(int f, int s)
{
    return mas[f].pos < mas[s].pos;
}

int uget(int ind, int l, int r, int num)
{
    if(l == r)
        return useg[ind];
    int rval;
    if(num > (l + r) / 2)
        rval = uget(ind * 2 + 1, (l + r) / 2 + 1, r, num);
    else
        rval = uget(ind * 2, l, (l + r) / 2, num);
    return max(rval, useg[ind]);
}
int lget(int ind, int l, int r, int num)
{
    if(l == r)
        return lseg[ind];
    int rval;
    if(num > (l + r) / 2)
        rval = lget(ind * 2 + 1, (l + r) / 2 + 1, r, num);
    else
        rval = lget(ind * 2, l, (l + r) / 2, num);
    return max(rval, lseg[ind]);
}
void uupd(int ind, int l, int r, int L, int R, int x)
{
    if(L > R || R < mas[unum[l]].pos || L > mas[unum[r]].pos)
        return;
    if(L <= mas[unum[l]].pos && R >= mas[unum[r]].pos)
    {
        useg[ind] = max(useg[ind], x);
        return;
    }
    uupd(ind * 2, l, (l + r) / 2, L, min(R, mas[unum[(l + r) / 2]].pos), x);
    uupd(ind * 2 + 1, (l + r) / 2  + 1, r, max(L, mas[unum[(l + r) / 2 + 1]].pos), R, x);
}
void lupd(int ind, int l, int r, int L, int R, int x)
{
    if(L > R || R < mas[lnum[l]].pos || L > mas[lnum[r]].pos)
        return;
    if(L <= mas[lnum[l]].pos && R >= mas[lnum[r]].pos)
    {
        lseg[ind] = max(lseg[ind], x);
        return;
    }
    lupd(ind * 2, l, (l + r) / 2, L, min(R, mas[lnum[(l + r) / 2]].pos), x);
    lupd(ind * 2 + 1, (l + r) / 2  + 1, r, max(L, mas[lnum[(l + r) / 2 + 1]].pos), R, x);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    for(int i(0); i < MAXN * 5; ++i)
        useg[i] = lseg[i] = 0;
    cin >> n >> q;
    for(int i(0); i < q; ++i)
    {
        cin >> x >> y >> mas[i].c;
        if(mas[i].c == 'U')
            mas[i].pos = y, unum[usi++] = i;
        else
            mas[i].pos = x, lnum[lsi++] = i;
    }
    if(usi)
        sort(unum, unum + usi, comp);
    if(lsi)
        sort(lnum, lnum + lsi, comp);
    for(int i(0); i < usi; ++i)
        mas[unum[i]].num = i;
    for(int i(0); i < lsi; ++i)
        mas[lnum[i]].num = i;
    for(int i(0); i < q; ++i)
    if(mas[i].c == 'U')
    {
        int t = uget(1, 0, usi - 1, mas[i].num);
        cout << mas[i].pos - t << '\n';
        if(lsi)
            lupd(1, 0, lsi - 1, n + 1 - mas[i].pos, n - t, n + 1 - mas[i].pos);
        uupd(1, 0, usi - 1, mas[i].pos, mas[i].pos, mas[i].pos);
    }
    else
    {
        int t = lget(1, 0, lsi - 1, mas[i].num);
        cout << mas[i].pos - t << '\n';
        if(usi)
            uupd(1, 0, usi - 1, n + 1 - mas[i].pos, n - t, n + 1 - mas[i].pos);
        lupd(1, 0, lsi - 1, mas[i].pos, mas[i].pos, mas[i].pos);
    }
    return 0;
}