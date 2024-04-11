#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <complex>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100010;
int n;
vector<int> d[N];
int a[N];

int main()
{
    for (int x = 2; x < N; x++)
        for (int y = x; y < N; y += x)
            d[y].push_back(x);

    scanf("%d", &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        for (int y : d[x])
            a[y]++;
    }
    int ans = 1;
    for (int i = 0; i < N; i++)
        ans = max(ans, a[i]);
    printf("%d\n", ans);


    return 0;
}