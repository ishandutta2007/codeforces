#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = 200;
int a[N];
bool used[N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);

    int cnt = 0;
    int ans = 0;
    while (cnt != n)
    {
        int st = 0;
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                st = i;
                break;
            }
        }
        int curW = 1;
        used[st] = 1;
        cnt++;
        ans++;
        for (int i = st + 1; i < n; i++)
        {
            if (!used[i] && a[i] >= curW)
            {
                used[i] = 1;
                curW++;
                cnt++;
            }
        }
    }           
    printf("%d", ans);

    return 0;
}