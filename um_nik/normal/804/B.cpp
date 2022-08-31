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

const int MOD = (int)1e9 + 7;
int add(int x, int y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}

const int N = (int)1e6 + 7;
int n, m;
char s[N];
int a[N];
int ans = 0;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%s", s);
    m = strlen(s);
    s[m] = 'a';
    m++;
    int lst = -1;
    for (int i = 0; i < m; i++)
    {
        if (s[i] == 'a')
        {
            if (lst != -1)
                a[n++] = i - lst - 1;
            lst = i;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ans = add(ans, a[i]);
        a[i - 1] = add(a[i - 1], add(a[i], a[i]));
    }
    printf("%d\n", ans);


    return 0;
}