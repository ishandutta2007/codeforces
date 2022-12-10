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
const int MAXN = 1e5 + 10;

int n, k;
string pre("1"), mas[MAXN];
bool f(1);
char yep(0);

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
}

bool dfs(int i, int j)
{
    int beg = j;
    mas[i][j] = pre[j];
    yep = 0;
    for(++j; j < k && mas[i][j] != '?'; ++j)
    if(!yep)
        if(mas[i][j] > pre[j])
            yep = 1;
        else if(mas[i][j] < pre[j])
            yep = 2;

    if(yep == 2)
    {
        for(; j < k; ++j)
            mas[i][j] = (mas[i][j] == '?' ? '0' : mas[i][j]);
        if(pre[beg] == '9')
        {
            mas[i][beg] = '0';
            return 0;
        }
        else
        {
            mas[i][beg] = pre[beg] + 1;
            return 1;
        }
    }

    if(yep == 1 || j == k)
    {
        for(; j < k; ++j)
            mas[i][j] = (mas[i][j] == '?' ? '0' : mas[i][j]);
        return 1;
    }

    yep = dfs(i, j);

    if(yep)
        return 1;
    else if(pre[beg] == '9')
    {
        mas[i][beg] = '0';
        return 0;
    }
    else
        mas[i][beg] = pre[beg] + 1;
    return 1;
}

void solve()
{
    for(int i(0); i < n; ++i)
    {
        yep = 0;
        for(int j(0); j < mas[i].size(); ++j)
            yep |= mas[i][j] == '?';
        if(!yep)
        {
            f &= stoi(pre) <= stoi(mas[i]);
            if(!f)
                return;
            pre = to_string(stoi(mas[i]) + 1LL);
            continue;
        }
        if(mas[i].size() > pre.size())
        {
            if(mas[i][0] == '?')
                mas[i][0] = '1';
            for(int j(1); j < mas[i].size(); ++j)
                mas[i][j] = (mas[i][j] == '?' ? '0' : mas[i][j]);
        }
        else if(mas[i].size() < pre.size())
            f = 0;
        else
        {
            k = pre.size();
            yep = 0;
            int j(0);

            for(; mas[i][j] != '?'; ++j)
            if(!yep)
                if(mas[i][j] > pre[j])
                    yep = 1;
                else if(mas[i][j] < pre[j])
                    yep = 2;

            if(yep == 2)
                f = 0;
            else if(yep == 1)
                for(; j < k; ++j)
                    mas[i][j] = (mas[i][j] == '?' ? '0' : mas[i][j]);
            else
                f &= dfs(i, j);
        }
        if(!f)
            return;
        pre = to_string(stoi(mas[i]) + 1LL);
    }
}

void output()
{
    if(f)
    {
        cout << "YES\n";
        for(int i(0); i < n; ++i)
            cout << mas[i] << '\n';
    }
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}