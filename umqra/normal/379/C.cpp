#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e6;

struct Item
{
    int val, ind;
    Item () {}
};

bool cmp(const Item &a, const Item &b)
{
    return a.val < b.val;
}

Item a[N];
int ans[N];

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
        scanf("%d", &a[i].val);
        a[i].ind = i;
    }

    sort(a, a + n, cmp);

    int prevRate = 0;
    for (int i = 0; i < n; i++)
    {
        if (prevRate < a[i].val)
        {
            ans[a[i].ind] = a[i].val;
            prevRate = a[i].val;
        }
        else
        {
            ans[a[i].ind] = prevRate + 1;
            prevRate++;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
                                
    return 0;
}