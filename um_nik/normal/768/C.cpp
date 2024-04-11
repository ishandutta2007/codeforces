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

const int M = 1 << 10;
int n, m, k;
int a[2][M];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &k, &m);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        a[0][x]++;
    }
    while(k--)
    {
        for (int i = 0; i < M; i++)
            a[1][i] = 0;
        int t = 0;
        for (int i = 0; i < M; i++)
        {
            int x = a[0][i] / 2, y = a[0][i] / 2;
            if (a[0][i] & 1)
            {
                if (t == 0)
                    x++;
                else
                    y++;
                t ^= 1;
            }
            a[1][i ^ m] += x;
            a[1][i] += y;
        }
        for (int i = 0; i < M; i++)
            a[0][i] = a[1][i];
    }
    int l = 0, r = M - 1;
    while(!a[0][l]) l++;
    while(!a[0][r]) r--;
    printf("%d %d\n", r, l);

    return 0;
}