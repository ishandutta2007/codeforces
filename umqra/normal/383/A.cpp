#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18;
const int N = (int)3e5 + 100;
int a[N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }                   


    int sum = 0;
    ll ans = INF;
    ll curAns = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            curAns += sum;
        if (a[i] == 1)
            sum++;                      
    }

    ans = min(ans, curAns);

    curAns = 0;
    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 1)
            curAns += sum;
        if (a[i] == 0)
            sum++;
    }
    ans = min(ans, curAns);
    cout << ans;

    return 0;
}