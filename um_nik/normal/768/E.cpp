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

const int N = 200;
int g[N];

int main()
{
    for (int k = 1; k * (k + 1) / 2 <= 60; k++)
        for (int i = k * (k + 1) / 2; i < (k + 1) * (k + 2) / 2; i++)
            g[i] = k;

    int n;
    scanf("%d", &n);
    int ans = 0;
    while(n--)
    {
        int x;
        scanf("%d", &x);
        ans ^= g[x];
    }
    if (ans)
        printf("NO\n");
    else
        printf("YES\n");


    return 0;
}