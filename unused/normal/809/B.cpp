#include <bits/stdc++.h>
using namespace std;

vector<int> dishes = {(int)-1e9, 1, 100000, (int)1e9};

bool ask(int a, int b)
{
    printf("%d %d %d\n", 1, a, b);
    fflush(stdout);

#ifdef ONLINE_JUDGE
    char res[6];
    scanf("%s", res);
    return res[0] == 'T';
#else
    int x1 = lower_bound(dishes.begin(), dishes.end(), a) - dishes.begin();
    int y1 = lower_bound(dishes.begin(), dishes.end(), b) - dishes.begin();
    return min(dishes[x1] - a, a - dishes[x1 - 1]) <= min(dishes[y1] - b, b - dishes[y1 - 1]);
#endif
}

void answer(int a, int b)
{
    if (a > b) swap(a, b);
    printf("2 %d %d\n", a, b);
    fflush(stdout);
}

int n;

int bsearch(int lo, int hi)
{
    if (lo > hi) return -1;

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (ask(mid, mid + 1)) hi = mid;
        else lo = mid + 1;
    }

    if (lo > 1 && ask(lo, lo - 1) == false) return -1;
    if (lo < n && ask(lo, lo + 1) == false) return -1;

    return lo;
}

int main()
{
    int k;
    scanf("%d%d",&n,&k);

    if (n == 2)
    {
        answer(1, 2);
        return 0;
    }

    int d1 = bsearch(1, n);
    int d2 = bsearch(1, d1 - 1);
    if (d2 == -1) d2 = bsearch(d1 + 1, n);
    answer(d1, d2);
}