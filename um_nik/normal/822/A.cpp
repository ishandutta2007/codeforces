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


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int a, b;
    scanf("%d%d", &a, &b);
    ll ans = 1;
    for (int i = 1; i <= a && i <= b; i++)
        ans *= i;
    printf("%lld\n", ans);

    return 0;
}