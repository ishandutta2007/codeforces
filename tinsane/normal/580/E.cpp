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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

int n, l, r, m, k, c, L, R;
long long seg[MAXN * 4], p10[MAXN], lat[MAXN * 4], sum, nsum;
vector<long long> ps[MAXN];
string s;
char sig;
void sets(int, int, int);

inline void push(int ind, int l, int r)
{
    if(lat[ind] != -1)
    {
        int tc = c, tL = L, tR = R;
        c = lat[ind];
        L = l;
        R = r;
        sets(ind * 2, l, (l + r) / 2);
        sets(ind * 2 + 1, (l + r) / 2 + 1, r);
        c = tc;
        lat[ind] = -1;
        L = tL, R = tR;
    }
}

void sets(int ind, int l, int r)
{
    if(l >= L && r <= R)
    {
        seg[ind] = c * ps[0][r - l] % MODUL * p10[l] % MODUL;
        lat[ind] = c;
        return;
    }


    if(r < L || l > R)
        return;


    push(ind, l, r);
    sets(ind * 2, l, (l + r) / 2);
    sets(ind * 2 + 1, (l + r) / 2 + 1, r);
    seg[ind] = (seg[ind * 2] + seg[ind * 2 + 1]) % MODUL;
}

long long gets(int ind, int l, int r)
{
    if(r < L || l > R)
        return 0;


    if(l >= L && r <= R)
        return seg[ind];


    if(lat[ind] != -1)
        return lat[ind] * ps[0][min(R, r) - max(L, l)] % MODUL * p10[max(l, L)] % MODUL;


    return (gets(ind * 2, l, (l + r) / 2) + 
        gets(ind * 2 + 1, (l + r) / 2 + 1, r)) % MODUL;
}

void sets_q(int pL, int pR)
{
    L = pL;
    R = pR;
    sets(1, 0, n - 1);
}

long long gets_q(int pL, int pR)
{
    L = pL;
    R = pR;
    return gets(1, 0, n - 1);
}

void init()
{
    cin >> n >> m >> k >> s;
    m += k;


    for(int i(0); i < MAXN * 4; ++i)
        lat[i] = -1, seg[i] = 0;


    p10[0] = 1;
    for(int i(1); i < n; ++i)
        p10[i] = p10[i - 1] * 10 % MODUL;


    for(int i(0); i < n; ++i)
    {
        ps[i].resize(n / (i + 1));
        ps[i][0] = 1;
        for(int j(1); j < ps[i].size(); ++j)
            ps[i][j] = (ps[i][j - 1] + p10[(i + 1) * j]) % MODUL;
    }


    for(int i(0); i < n; ++i)
        c = s[i] - '0', sets_q(i, i);
}

void solve()
{
    while(m--)
    {
        cin >> sig >> l >> r >> c;
        --l, --r;


        if(sig == '1')
        {
            sets_q(l, r);
            continue;
        }


        sum = gets_q(l, l + c - 1);
        int cn = (r - l + 1) / c, rn = l - 1 + cn * c;
        if(cn > 0)
        {
            nsum = gets_q(l, rn);
            if(nsum != sum * ps[c - 1][cn - 1] % MODUL)
            {
                cout << "NO\n";
                continue;
            }
        }


        cn = (r - l + 1) % c;
        if(cn)
        {
            sum = gets_q(l, l + cn - 1);
            nsum = gets_q(r - cn + 1, r);
            if(nsum != sum * p10[r - l - cn + 1] % MODUL)
            {
                cout << "NO\n";
                continue;
            }
        }


        cout << "YES\n";
    }
}


void output()
{
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}