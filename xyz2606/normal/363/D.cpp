#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long cst;
int le, ri, mid, a[111111], b[111111], n, m, A, sa[111111], sb[111111];
int main()
{
    scanf("%d%d%d", &n, &m, &A);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    sa[n + 1] = 0; for(int i = n; i >= 1; i--) sa[i] = sa[i + 1] + a[i];
    sb[0] = 0; for(int i = 1; i <= m; i++) sb[i] = sb[i - 1] > 2000000000 - b[i]?2000000001:sb[i - 1] + b[i];
    le = 0; ri = min(n, m);
    while(le < ri)
    {
        cst = 0; mid = (le + ri + 1) / 2;
        for(int i = 1; i <= mid; i++) if(b[i] > a[n - mid + i]) cst += (b[i] - a[n - mid + i]);
        if(cst <= A) le = mid; else ri = mid - 1;
    }
    printf("%d %d\n", le, max(sb[le] - A, 0));
    cst = 0;
    
}