#include <iostream>
#include <set>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e6 + 10;

set <pii> a;
set <pii> b;


int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int f, s;
        scanf("%d%d", &f, &s);
        sum += f;
    }

    int t = 1000 * n - sum;
    for (int i = 0; i <= n; i++)
    {
        if (abs(t - 1000 * i) <= 500)
        {
            for (int s = 0; s < i; s++)
                printf("%c", 'A');
            for (int s = 0; s < n - i; s++)
                printf("%c", 'G');
            return 0;
        }
    }

    cout << -1;
    return 0;
}