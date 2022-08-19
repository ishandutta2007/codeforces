#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair
#define X first
#define Y second

const int N = 100100;
int n;
ll cf, cm;
ll mAns = -1;
int szAns = -1;
pli a[N];
ll A;
ll sumPref[N], sumSuff[N];
ll m;
ll b[N];

void read()
{
    scanf("%d%lld%lld%lld%lld", &n, &A, &cf, &cm, &m);
    for (int i = 0; i < n; i++)
    {
        a[i].second = i;
        scanf("%lld", &a[i].first);
    }
    sort(a, a + n);
    sumPref[0] = 0;
    for (int i = 0; i < n; i++)
        sumPref[i + 1] = sumPref[i] + a[i].first;
    sumSuff[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        sumSuff[i] = sumSuff[i + 1] + A - a[i].first;
    return;
}

void solve()
{
    if (sumSuff[0] <= m)
    {
        printf("%lld\n", cf * n + cm * A);
        for (int i = 0; i < n; i++)
            printf("%lld ", A);
        printf("\n");
        return;
    }
    int idx = 1;
    for (int i = 0; i <= n; i++)
    {
        if (sumSuff[i] > m) continue;
        ll lft = m - sumSuff[i];
        while(idx < i)
        {
            ll x = (sumPref[idx] + lft) / idx;
            if (x > a[idx].first)
                idx++;
            else
                break;
        }
        ll x = (sumPref[idx] + lft) / idx;
        ll val = cf * (n - i) + cm * x;
        if (val > mAns)
        {
            mAns = val;
            szAns = i;
        }
    }
    printf("%lld\n", mAns);
    idx = 1;
    while(idx < szAns)
    {
        ll x = (sumPref[idx] + m - sumSuff[szAns]) / idx;
        if (x > a[idx].first)
            idx++;
        else
            break;
    }
    ll x = (sumPref[idx] + m - sumSuff[szAns]) / idx;
    for (int i = 0; i < idx; i++)
        a[i].first = x;
    for (int i = szAns; i < n; i++)
        a[i].first = A;
    for (int i = 0; i < n; i++)
        b[a[i].second] = a[i].first;
    for (int i = 0; i < n; i++)
        printf("%lld ", b[i]);
    printf("\n");
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    solve();

    return 0;
}