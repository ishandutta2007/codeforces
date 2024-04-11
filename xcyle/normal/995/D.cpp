#include<bits/stdc++.h>
#define maxn 21
using namespace std;
int n, q;
long long a[300005], val, sum;
int pos;
inline long long read()
{
    long long x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < (1 << n); i++)
    {
        a[i] = read();
        sum += a[i];
    }
    double w = (1 << n);
    printf("%.8lf\n", 1.0 * sum / w);
    for (int i = 1; i <= q; i++)
    {
        pos = read();
        val = read();
        sum -= a[pos];
        sum += val;
        printf("%.8lf\n", 1.0 * sum / w);
        a[pos] = val;
    }
    return 0;
}