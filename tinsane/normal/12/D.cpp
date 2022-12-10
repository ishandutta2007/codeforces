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
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 5e5 + 10;

struct que
{
    int a, b, c;
};

que mas[MAXN];
int n, ans(0), segt[MAXN * 5];

bool comp(que& f, que& s)
{
    return f.b < s.b;
}
bool comp1(que& f, que& s)
{
    return f.a < s.a;
}
void sque()
{
    sort(mas, mas + n, comp);
    int num = 0;
    for(int i(0), j; i < n;)
    {
        for(j = i + 1; j < n && mas[j].b == mas[i].b; ++j);
        for(; i < j; ++i)
            mas[i].b = num;
        ++num;
    }
}
void ins(int ind, int l, int r, int pos, int v)
{
    if(v > segt[ind])
        segt[ind] = v;
    if(l == r)
        return;
    if((l + r) / 2 >= pos)
        ins(ind * 2, l, (l + r) / 2, pos, v);
    else
        ins(ind * 2 + 1, (l + r) / 2 + 1, r, pos, v);
}
int get(int ind, int l, int r, int L)
{
    if(l == L)
        return segt[ind];
    if(L >= (l + r) / 2 + 1)
        return get(ind * 2 + 1, (l + r) / 2 + 1, r, L);
    return max(segt[ind * 2 + 1], get(ind * 2, l, (l + r) / 2, L));
}


int main()
{
    for(int i(0); i < MAXN * 5; ++i)
        segt[i] = -1;
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i].a;
    for(int i(0); i < n; ++i)
        cin >> mas[i].b;
    for(int i(0); i < n; ++i)
        cin >> mas[i].c;
    sque();
    sort(mas, mas + n, comp1);

    for(int i(n - 1), j; i >= 0;)
    {
        for(j = i; j >= 0 && mas[j].a == mas[i].a; --j)
            ans += (get(1, 0, n - 1, mas[j].b + 1) > mas[j].c);
        for(; i > j; --i)
            ins(1, 0, n - 1, mas[i].b, mas[i].c);
    }

    cout << ans;
    return 0;
}