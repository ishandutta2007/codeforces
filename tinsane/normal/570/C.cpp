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
const int MAXN = 1e3 + 10;

int n, m, cnt(0), pos;
string s;
char c;

void init()
{
    cin >> n >> m;
    cin >> s;
    for(int i(0); i < n; ++i)
        cnt += s[i] == '.';
    for(int i(1); i < n; ++i)
        cnt -= (s[i] == '.' && s[i - 1] != '.');
    if(s[0] == '.')
        --cnt;
}

void solve()
{
}

void output()
{
    for(int i(0); i < m; ++i)
    {
        cin >> pos >> c;
        --pos;
        if((c == '.' && s[pos] == '.') ||
            (c != '.' && s[pos] != '.'))
        {
            cout << cnt << '\n';
            continue;
        }
        if(c == '.')
        {
            if(pos == 0)
            {
                if(n != 1 && s[pos + 1] == '.')
                    ++cnt;
            }
            else if(pos == n - 1)
            {
                if(s[pos - 1] == '.')
                    ++cnt;
            }
            else
            {
                if(s[pos - 1] == '.')
                    ++cnt;
                if(s[pos + 1] == '.')
                    ++cnt;
            }
        }
        else
        {
            if(pos == 0)
            {
                if(n != 1 && s[pos + 1] == '.')
                    --cnt;
            }
            else if(pos == n - 1)
            {
                if(s[pos - 1] == '.')
                    --cnt;
            }
            else
            {
                if(s[pos - 1] == '.')
                    --cnt;
                if(s[pos + 1] == '.')
                    --cnt;
            }
        }
        cout << cnt << '\n';
        s[pos] = c;
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