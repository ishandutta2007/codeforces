#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, a[500001], sum[500001], top;
struct node
{
    long long v, len;
} s[500001];
void checkmin(long long &x, long long y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    long long tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        long long tlen = 1;
        while (top >= 0 && s[top].v > a[i])
        {
            tmp -= s[top].v * s[top].len;
            tlen += s[top].len;
            top--;
        }
        tmp += tlen * a[i];
        sum[i] += tmp;
        s[++top] = (node){a[i], tlen};
    }
    top = 0;
    for (int i = n; i >= 1; i--)
    {
        long long tlen = 1;
        while (top >= 0 && s[top].v > a[i])
        {
            tmp -= s[top].v * s[top].len;
            tlen += s[top].len;
            top--;
        }
        tmp += tlen * a[i];
        sum[i] += tmp - a[i];
        s[++top] = (node){a[i], tlen};
    }
    long long maxx = 0, pos = -1, minn;
    for (int i = 1; i <= n; i++)
    {
        if (sum[i] > maxx)
        {
            maxx = sum[i];
            pos = i;
        }
    }
    minn = a[pos];
    for (int i = pos - 1; i >= 1; i--)
    {
        checkmin(a[i], minn);
        checkmin(minn, a[i]);
    }
    minn = a[pos];
    for (int i = pos + 1; i <= n; i++)
    {
        checkmin(a[i], minn);
        checkmin(minn, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", a[i]);
    }
    return 0;
}