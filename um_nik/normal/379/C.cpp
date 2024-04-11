#include <iostream>
#include <algorithm>
using namespace std;

struct ttt
{
    int val, num;
};

bool cmp (ttt a, ttt b)
{
    return (a.val < b.val);
}

ttt a[400000];
int n;
int k;
int b[400000];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        a[i].num = i;
        scanf("%d", &a[i].val);
    }
    sort(a, a + n, cmp);
    k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, a[i].val);
        b[a[i].num] = k;
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}