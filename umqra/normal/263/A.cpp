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

int m[5][5];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int ans;
    for (int i = 0; i < 5; i++)
        for (int s = 0; s < 5; s++)
        {
            scanf("%d", &m[i][s]);
            if (m[i][s] == 1)
                ans = abs(i - 2) + abs(s - 2);
        }

    printf("%d", ans);

    return 0;
}