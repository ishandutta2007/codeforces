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

    int n, k;
    scanf("%d%d", &n, &k);
    int m = (n - 1) / k;
    int r = (n - 1) % k;
    printf("%d\n", 2 * m + min(r, 2));
    int last = 1;
    for (int i = 0; i < k; i++) {
        int len = m;
        if (i < r) len++;
        last++;
        printf("1 %d\n", last);
        for (int j = 1; j < len; j++) {
            printf("%d %d\n", last, last + 1);
            last++;
        }
    }

    return 0;
}