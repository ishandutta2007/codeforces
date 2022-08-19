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

const int A = 27;
const int N = 100100;
char s[N];
int n;

int SA[N], nSA[N];
int id[N], nid[N];
int a[N];

int revSA[N];
int LCP[N];

int L[N], R[N];
pii b[N];

void buildSA()
{
    for (int i = 0; i <= max(n, A); i++)
        a[i] = 0;
    for (int i = 0; i < n; i++)
        a[(int)(s[i] - 'a') + 1]++;
    for (int i = 1; i <= A; i++)
        a[i] += a[i - 1];
    for (int i = 0; i < n; i++)
    {
        int x = (int)(s[i] - 'a');
        SA[a[x]++] = i;
    }
    id[SA[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        id[SA[i]] = id[SA[i - 1]];
        if (s[SA[i]] != s[SA[i - 1]])
            id[SA[i]]++;
    }

    int len = 1;

    while(id[SA[n - 1]] < n - 1)
    {

        for (int i = 0; i <= n; i++)
            a[i] = 0;
        for (int i = 0; i < n; i++)
        {
            int p = SA[i];
            int q = (p + 2 * n - len) % n;
            a[id[q] + 1]++;
        }
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        for (int i = 0; i < n; i++)
        {
            int p = SA[i];
            int q = (p + 2 * n - len) % n;
            nSA[a[id[q]]++] = q;
        }
        nid[nSA[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            int q1 = nSA[i - 1], q2 = nSA[i];
            int p1 = (q1 + len) % n, p2 = (q2 + len) % n;
            nid[q2] = nid[q1];
            if (id[q1] != id[q2] || id[p1] != id[p2])
                nid[q2]++;
        }
        for (int i = 0; i < n; i++)
        {
            SA[i] = nSA[i];
            id[i] = nid[i];
        }

        len *= 2;
    }

    n--;
    for (int i = 0; i < n; i++)
        SA[i] = SA[i + 1];
    for (int i = 0; i < n; i++)
        revSA[SA[i]] = i;

    len = 0;
    for (int p = 0; p < n; p++)
    {
        if (len > 0) len--;
        if (revSA[p] == n - 1)
        {
            LCP[n - 1] = -1;
            len = 0;
            continue;
        }
        int q = SA[revSA[p] + 1];
        while(p + len < n && q + len < n && s[p + len] == s[q + len]) len++;
        LCP[revSA[p]] = len;
    }
/*
    for (int i = 0; i < n; i++)
        printf("%d ", SA[i]);
    printf("\n");
    for (int i = 0; i < n - 1; i++)
        printf("%d ", LCP[i]);
    printf("\n");
*/
}

void solve()
{
    scanf(" %s", s);
    n = strlen(s);
    s[n] = 'a';
    for (int i = 0; i < n; i++)
        s[i]++;
    n++;
    buildSA();

    ll ans = (ll)n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
        L[i] = R[i] = i;
    int m = 0;
    for (int i = 0; i < n - 1; i++)
        b[m++] = mp(LCP[i], i);
    sort(b, b + m);
    reverse(b, b + m);
    for (int i = 0; i < m; i++)
    {
        int p = b[i].second;
        int q = p + 1;
        ans += 2LL * b[i].first * (p - L[p] + 1) * (R[q] - q + 1);
        R[L[p]] = R[q];
        L[R[q]] = L[p];
    }
    printf("%lld\n", ans);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t--) solve();

    return 0;
}