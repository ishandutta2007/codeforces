#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define mp make_pair
typedef long long ll;
const int N = (int)1e5 + 10;
int a[N], b[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            cnt++;
    if (cnt < 3)
        puts("YES");
    else
        puts("NO");
    return 0;
}