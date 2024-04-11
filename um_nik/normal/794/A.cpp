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

const int N = 100100;
int l, r;
int n;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &l);
    scanf("%d%d", &l, &r);
    scanf("%d", &n);
    int ans = 0;
    while(n--)
    {
        int x;
        scanf("%d", &x);
        if (l < x && x < r)
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}