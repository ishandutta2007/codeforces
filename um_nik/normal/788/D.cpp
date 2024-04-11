#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

vector<int> ans;

int query(int x, int y)
{
    printf("0 %d %d\n", x, y);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

const int C = (int)1e8;

void solve(int l, int r)
{
    if (l + 1 >= r) return;
    if ((r - l) % 2 == 0)
    {
        int m = l + (r - l) / 2;
        int d = query(m, m);
        if (d == m - l) return;
        if (query(m - d, m - d) == 0)
        {
            ans.push_back(m - d);
            solve(l, m - d);
            solve(m - d, r);
        }
        else
        {
            ans.push_back(m + d);
            solve(l, m + d);
            solve(m + d, r);
        }
    }
    else
    {
        int m = l + (r - l) / 2;
        int d = query(m, m);
        if (d == m - l)
        {
            if (query(r - 1, r - 1) == 0)
            {
                ans.push_back(r - 1);
                solve(l, r - 1);
            }
            return;
        }
        if (query(m - d, m - d) == 0)
        {
            ans.push_back(m - d);
            solve(l, m - d);
            solve(m - d, r);
        }
        else
        {
            ans.push_back(m + d);
            solve(l, m + d);
            solve(m + d, r);
        }
    }
}

void printAns()
{
    int x = -C;
    for (int y : ans)
        if (x == y)
            x++;
    vector<int> ansX, ansY;
    for (int y : ans)
    {
        if (query(y, x) == 0)
            ansX.push_back(y);
        if (query(x, y) == 0)
            ansY.push_back(y);
    }
    printf("1 %d %d\n", (int)ansX.size(), (int)ansY.size());
    for (int y : ansX)
        printf("%d ", y);
    printf("\n");
    for (int y : ansY)
        printf("%d ", y);
    printf("\n");
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int l = -C + query(-C, -C);
    int r = C - query(C, C);

    if (l == r)
    {
        ans.push_back(l);
        printAns();
        return 0;
    }

    ans.push_back(l);
    ans.push_back(r);
    solve(l, r);
    sort(ans.begin(), ans.end());
    printAns();

    return 0;
}