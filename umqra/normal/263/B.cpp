#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define X first
#define Y second
#define mp make_pair

int a[10000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    if (n < k)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int t = n - k;

    if (n == k)
    {
        cout << 0 << ' ' << 0;
        return 0;
    }
                
    cout << a[t] << ' ' << 0;

    return 0;
}