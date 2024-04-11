#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
const int N = 500500;
int n;
pii a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].second, &a[i].first);
    sort(a, a + n);
    int ans = 0;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (x < a[i].second)
        {
            ans++;
            x = a[i].first;
        }
    }
    printf("%d\n", ans);

    return 0;
}