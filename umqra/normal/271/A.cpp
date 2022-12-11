#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define X first
#define Y second
#define mp make_pair

bool used[10];

bool check(int n)
{
    fill(used, used + 10, 0);
    while (n)
    {
        if (used[n % 10])
            return false;
        used[n % 10] = 1;
        n /= 10;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);

    for (int i = n + 1;; i++)
    {
        if (check(i))
        {
            printf("%d", i);
            return 0;
        }
    }

    return 0;
}