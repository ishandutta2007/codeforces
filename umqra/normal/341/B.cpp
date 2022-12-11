#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

#ifdef UMQRA
    #define getTime() fprintf(stderr, "Running time:%.3lf seconds\n", (double)(clock()) / CLOCKS_PER_SEC)
#else
    #define getTime()
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair
const int pow2 = (1 << 20);
const int N = (int)1e5;
int a[N];

struct SegmentTree
{
    int tree[pow2 * 2];
    void build()
    {
        for (int i = 0; i < pow2 * 2; i++)
            tree[i] = 0;
    }
    void setVal(int pos, int val, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l == r)
        {
            tree[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
            setVal(pos, val, 2 * v, l, m);
        else
            setVal(pos, val, 2 * v + 1, m + 1, r);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
    int getMax(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l >= a && r <= b)
            return tree[v];
        if (l > b || r < a)
            return 0;
        int m = (l + r) / 2;
        return max(getMax(a, b, 2 * v, l, m), getMax(a, b, 2 * v + 1, m + 1, r));
    }
} tree;
                        
int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    tree.build();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        tree.setVal(a[i], tree.getMax(1, a[i] - 1) + 1);
    cout << tree.getMax(1, n);

    return 0;
}