#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <time.h>
#include <string>
#include <vector>
#include <math.h>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define ft first
#define sc second
#define mp make_pair
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;
typedef long double ld;
typedef pair <li, li> pli;
typedef pair <int, int> pii;

const int N = 300010;

map <li, li> lf, rt;

li n, k, ans, a[N];

int main()
{

    scanf("%I64d %I64d", &n, &k);

    forn(i, n)
    {
        scanf("%I64d", &a[i]);
        
        rt[a[i]]++;
    }

    forn(i, n)
    {
        li k1 = 0, k2 = 0;

        if(a[i] % k == 0)
            k1 = lf[a[i] / k];

        rt[a[i]]--;

        k2 = rt[a[i] * k];
        
        ans += k1 * k2;

        lf[a[i]]++;
    }

    printf("%I64d", ans);
     
    return 0;
}