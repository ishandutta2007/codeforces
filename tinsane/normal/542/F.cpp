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
struct som
{
    int t, q;
};

struct cl
{
    bool operator() (int f, int s)
    {
        return f > s;
    }
};

int n, T, sum(0), t1, t2;
priority_queue<int, vector<int>, cl> res, tres;
som mas[1000];

bool comp(som& f, som& s)
{
    return f.t > s.t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> T;
    for(int i(0); i < n; ++i)
        cin >> mas[i].t >> mas[i].q, mas[i].t = T - mas[i].t;
    sort(mas, mas + n, comp);
    for(int i(0); i < 1024; ++i)
        res.push(0);
    for(int t(max(T, 10)), i(0); t >= 0; --t)
    {
        for(; i < n && mas[i].t == t; ++i)
        if(mas[i].q > res.top())
        {
            res.pop();
            res.push(mas[i].q);
        }
        if(t == 0)
            continue;
        for(;res.size();)
        {
            t1 = res.top();
            res.pop();
            t2 = res.top();
            res.pop();
            tres.push(t1 + t2);
        }
        for(;tres.size();)
            res.push(tres.top()), tres.pop();
        if(t > 10)
        {
            for(int i(0); i < 512; ++i)
                res.push(0);
        }
    }
    cout << res.top();
    return 0;
}