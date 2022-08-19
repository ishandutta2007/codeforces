#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int N = 500500;
int n;
int a[N];
bool b[N];
int ans;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    b[0] = b[n - 1] = 1;
    for (int i = 1; i < n - 1; i++)
        b[i] = (a[i] == a[i - 1]) || (a[i] == a[i +  1]);
    int l = 0;
    while(l < n)
    {
        if (b[l])
        {
            l++;
            continue;
        }
        int r = l + 1;
        while(!b[r]) r++;
        ans = max(ans, (r - l + 1) / 2);
        int nl = r + 1;
        r--;
        int x = a[l - 1], y = a[r + 1];
        while(l <= r)
        {
            a[l++] = x;
            a[r--] = y;
        }
        l = nl;
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}