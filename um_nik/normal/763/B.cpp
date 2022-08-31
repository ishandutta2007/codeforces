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

    int n;
    scanf("%d", &n);
    printf("YES\n");
    while(n--)
    {
        int x1, y1;
        scanf("%d%d", &x1, &y1);
        x1 = abs(x1) & 1;
        y1 = abs(y1) & 1;
        printf("%d\n", 1 + x1 + 2 * y1);
        scanf("%d%d", &x1, &y1);
    }


    return 0;
}