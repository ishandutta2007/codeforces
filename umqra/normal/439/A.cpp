#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 10;
int a[N], val[N];

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    int t = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        if (i != n - 1)
        {
            sum += 10;
            t += 2;
        }
    }
    
    if (sum > d)
    {
        puts("-1");
        return 0;
    }
    printf("%d", t + (d - sum) / 5);
    
    return 0;
}