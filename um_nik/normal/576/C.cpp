#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int M = 1000;
const int L = M * M;

struct Point
{
    int x, y;
    int id;
    int val;

    void scan(int _id)
    {
        id = _id;
        scanf("%d%d", &x, &y);
        int xx = x / M, yy = y;
        if (xx == M) xx--;
        if (yy == L) yy--;
        if (xx & 1) yy = L - 1 - yy;
        val = xx * L + yy;
    }

    bool operator < (const Point &a) const
    {
        return val < a.val;
    }
};

const int N = (int)1e6 + 100;
int n;
Point a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        a[i].scan(i + 1);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i].id);
    printf("\n");

    return 0;
}