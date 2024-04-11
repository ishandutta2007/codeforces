#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a, b;
int k, p;

int main()
{
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x & 1)
            a.push_back(x);
        else
            b.push_back(x);
    }
    p = k - p;
    if (((p - a.size()) % 2 != 0) || p > a.size())
    {
        printf("NO\n");
        return 0;
    }
    k -= p;
    if (k > b.size() + ((a.size() - p) / 2))
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    if (k == 0)
    {
        for (int i = 0; i < p - 1; i++)
            printf("1 %d\n", a[i]);
        printf("%d ", n - p + 1);
        for (int i = p - 1; i < a.size(); i++)
            printf("%d ", a[i]);
        for (int i = 0; i < b.size(); i++)
            printf("%d ", b[i]);
        printf("\n");
        return 0;
    }
    for (int i = 0; i < p; i++)
        printf("1 %d\n", a[i]);
    while (k > 1)
    {
        if (p < a.size())
        {
            printf("2 %d %d\n", a[p], a[p + 1]);
            p += 2;
        }
        else
        {
            printf("1 %d\n", b.back());
            b.pop_back();
        }
        k--;
    }
    printf("%d ", a.size() - p + b.size());
    for (; p < a.size(); p++)
        printf("%d ", a[p]);
    for (int i = 0; i < b.size(); i++)
        printf("%d ", b[i]);
    printf("\n");
    return 0;
}