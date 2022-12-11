#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = 210;
const int INF = (int)1e9;
int a[N], fst[N], scnd[N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int res = -INF;
    for (int i = 0; i < n; i++)
        for (int s = i; s < n; s++)
        {
            int indF = 0, indS = 0;
            for (int q = 0; q < n; q++)
            {
                if (q < i || q > s)
                    fst[indF++] = a[q];
                else
                    scnd[indS++] = a[q];
            }
            sort(fst, fst + indF, greater<int>());
            sort(scnd, scnd + indS);
            int ans = 0;
            int cnt = 0;
            for (int q = 0; q < min(k, min(indF, indS)); q++)
            {
                if (fst[q] > scnd[q])
                {
                    ans += fst[q];
                    cnt++;
                }
                else
                    break;
            }
            for (int q = cnt; q < indS; q++)
                ans += scnd[q];
            res = max(res, ans);
        }
    cout << res;
    return 0;
}