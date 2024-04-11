#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, A, cf, cm;

long long m;

int a[N], b[N], ord[N];

long long sum[N];

bool byA(const int &i, const int &j) {
    return a[i] < a[j];
}

int main() {
    scanf("%d%d%d%d", &n, &A, &cf, &cm);
    cin >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        b[i] = a[i];
        ord[i] = i;
    }
    sort(ord, ord + n, byA);
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + a[i];
    }
    long long ans = -1, ansi = -1, ansm = -1;
    for (int i = 0, j = 0; i <= n; ++i) {
        //i to n - 1 shall be all perfect then maxmize the minimum among 0 to i - 1
        long long cost = 0, tmp = 0;
        cost = (long long)A * (n - i) - (sum[n] - sum[i]);
        if (cost > m) {
            continue;
        }
        tmp += (n - i) * cf;
        long long left = m - cost;
        while (j < i && (long long)j * a[j] - sum[j] <= left) {
            ++j;
        }
        int mins = 0;
        if (j) {
            mins = min((long long)A, (left + sum[j]) / j);
        } else {
            mins = A;
        }
        tmp += (long long)mins * cm;
        if (tmp > ans) {
            ans = tmp;
            ansi = i;
            ansm = mins;
        }
    }
    cout << ans << endl;
    long long cost = 0, mins = A, maxs = 0;
    for (int i = 0; i < n; ++i) {
        int delta = 0, u = b[ord[i]];
        if (i >= ansi) {
            delta = A - u;
        } else {
            delta = max(0ll, ansm - u);
        }
        b[ord[i]] += delta;
        cost += delta;
        mins = min(mins, (long long)b[ord[i]]);
        maxs += b[ord[i]] == A;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
    }
    assert(cost <= m && mins * cm + maxs * cf == ans);
    return 0;
}