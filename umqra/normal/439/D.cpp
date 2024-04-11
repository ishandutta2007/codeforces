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
int a[N], b[N];
ll sumA[N], sumB[N];


int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    
    sort(a, a + n);
    sort(b, b + m);
    
    sumB[m - 1] = b[m - 1];
    for (int i = m - 2; i >= 0; i--)
        sumB[i] = sumB[i + 1] + b[i];
    
    sumA[0] = a[0];
    for (int i = 1; i < n; i++)
        sumA[i] = sumA[i - 1] + a[i];
    
    ll sum = 0;
    int globCnt = 0;
    ll lst = 0;
    int cnt = 0;
    
    ll ans = (ll)1e18;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != lst)
        {
            sum += (ll)lst * cnt;
            globCnt += cnt;
            lst = a[i];
            cnt = 1;
        }
        else
            cnt++;
        int pos = lower_bound(b, b + m, a[i] + 1) - b;
        int cntB = m - pos;
        ans = min(ans, (ll)a[i] * globCnt - sum + (sumB[pos] - (ll)cntB * a[i]));
    }
    
    sum = 0;
    globCnt = 0;
    lst = 0;
    cnt = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        if (b[i] != lst)
        {
            sum += (ll)lst * cnt;
            globCnt += cnt;
            lst = b[i];
            cnt = 1;
        }
        else
            cnt++;
        int pos = lower_bound(a, a + n, b[i]) - a;
        pos--;
        int cntA = pos + 1;
        ans = min(ans, sum - (ll)b[i] * globCnt + ((ll)cntA * b[i] - (pos < 0 ? 0 : sumA[pos])));
    }
    cout << ans;
    
    return 0;
}