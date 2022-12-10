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
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

struct tr
{
    int x, h;
    bool was;
};

bool comp(tr& f, tr& s)
{
    return f.x < s.x;
}
    int n, res(0);
    tr mas[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    for(int i(0); i < n; ++i)
        cin >> mas[i].x >> mas[i].h, mas[i].was = 0;
    sort(mas, mas + n, comp);
    mas[n - 1].was = 1;
    res = 2;
    for(int i(1); i < n - 1; ++i)
    if(mas[i - 1].was)
    {
        if(mas[i].x - mas[i].h > mas[i - 1].x + mas[i - 1].h)
            ++res;
        else
            if(mas[i].x + mas[i].h < mas[i + 1].x)
                mas[i].was = 1, ++res;
    }
    else
    {
        if(mas[i].x - mas[i].h > mas[i - 1].x)
            ++res;
        else
            if(mas[i].x + mas[i].h < mas[i + 1].x)
                ++res, mas[i].was = 1;
    }
    cout << res;
    return 0;
}