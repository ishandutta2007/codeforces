#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define X first
#define Y second
#define mp make_pair

int ans[(int)1e6 + 100];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n, k;
    scanf("%d%d", &n, &k);

    if (k * 3 > n)
    {
        puts("-1");
        return 0;
    }

    int cur = 1;
    for (int i = 1; i <= n;)
    {
        if (k == 3)
        {
            ans[i] = cur;
            ans[i + 1] = cur;
            ans[i + 2] = cur + 1;
            ans[i + 3] = cur + 1;
            ans[i + 4] = cur + 2;
            ans[i + 5] = cur;
            ans[i + 6] = cur + 1;
            ans[i + 7] = cur + 2;
            ans[i + 8] = cur + 2;
            i += 9;
            cur += 3;
            k -= 3;
        }
        else if (k == 0)
        {
            ans[i] = cur - 1;
            i++;
        }
        else
        {
            ans[i] = cur;
            ans[i + 1] = cur + 1;
            ans[i + 2] = cur;
            ans[i + 3] = cur + 1;
            ans[i + 4] = cur + 1;
            ans[i + 5] = cur;
            i += 6;
            cur += 2;
            k -= 2;
        }
    }   

    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);

    return 0;
}