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

const int N = 111;
int n, k;
int a[N][N];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    if (k > n * n)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; k > 0 && i < n; i++)
    {
        a[i][i] = 1;
        k--;
        for (int j = i + 1; k > 1 && j < n; j++)
        {
            a[i][j] = a[j][i] = 1;
            k -= 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}