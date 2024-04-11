#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = (int)1e6 + 7;
int n;
int a[N];
int b[N];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        b[i] = n;
    int lst = -n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            lst = i;
        b[i] = min(b[i], i - lst);
    }
    lst = 2 * n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0) lst = i;
        b[i] = min(b[i], lst - i);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}