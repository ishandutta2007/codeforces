#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int solve(int L, int R)
{
    int l = L, r = R;
    char res[10];
    while (l < r)
    {
        int mid = (l + r) >> 1;
        printf("1 %d %d\n", mid, mid + 1);
        fflush(stdout);
        scanf("%s", res);
        if (res[0] == 'T')
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
bool check(int x, int y)
{
    char res[10];
    printf("1 %d %d\n", x, y);
    fflush(stdout);
    scanf("%s", res);
    return res[0] == 'T';
}
int main(int argc, char const *argv[])
{
    scanf("%d%*d", &n);
    int ans1 = solve(1, n), ans2 = solve(1, ans1 - 1);
    if (ans2 == ans1 || !check(ans2, ans1))
    {
        ans2 = solve(ans1 + 1, n);
    }
    printf("2 %d %d", ans1, ans2);
    fflush(stdout);
    return 0;
}