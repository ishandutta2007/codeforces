#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, k;
int a[3000];
int ans;

int main()
{
    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int idx = n - 1;
    while (idx >= 0)
    {
        ans += 2 * (a[idx] - 1);
        idx -= k;
    }

    cout << ans << endl;

    return 0;
}