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

const int N = 400400;
int a[N];
int nxt[N];
int b[N];
int n, k;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++)
        b[i] = n + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        nxt[i] = b[a[i]];
        b[a[i]] = i;
    }

    set<pii> setik;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (setik.count(mp(-i, a[i])))
            setik.erase(mp(-i, a[i]));
        else
            ans++;
        if ((int)setik.size() == k)
            setik.erase(setik.begin());
        setik.insert(mp(-nxt[i], a[i]));
    }
    printf("%d\n", ans);

    return 0;
}