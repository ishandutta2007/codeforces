#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

long long  a[1010][1010];
long long  r[1010], c[1010];
long long  recc[1000100], recr[1000100];
//long long  rec[2000100];

int  main () {
    long long  n, m, k, p;
    cin >> n >> m >> k >> p;
    for (long long  i = 1; i <= n; i++)
        for (long long  j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    priority_queue <long long > q;
    for (long long  i = 1; i <= n; i++)
        q.push(r[i]);
    long long  ii = 1;
    while (ii <= k){
        long long  u = q.top();
        q.pop();
        recr[ii] = recr[ii - 1] + u;
        ii++;
        q.push(u - m * p);
    }
    ii--;
    priority_queue <long long > q2;
    for (long long  i = 1; i <= m; i++)
        q2.push(c[i]);
    long long  jj = 1;
    while (jj <= k){
        long long  u = q2.top();
        q2.pop();
        recc[jj] = recc[jj - 1] + u;
        jj++;
        q2.push(u - n * p);
    }
    jj--;
    long long  res = recr[0] + recc[k];
    for (long long  i = 1; i <= k; i++)
        res = max(res, recr[i] + recc[k - i] - i * (k - i) * p);
    cout << res;
}