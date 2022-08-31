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

const int INF = (int)1e9 + 100;
const int N = 100100;
int n;
int a[N];
int l = INF, r = -INF;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != l && a[i] != r)
            ans++;
    printf("%d\n", ans);


    return 0;
}