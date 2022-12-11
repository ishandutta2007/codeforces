#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair
                
const int pow2 = (1 << 18);
int a[pow2];
int tree[pow2 * 2];
bool setVal(int pos, int val, int v, int l, int r)
{
    if (l == r)
    {
        tree[v] = val;
        return 1;
    }
    int m = (l + r) / 2;
    bool t;
    if (pos <= m)
        t = setVal(pos, val, 2 * v, l, m);
    else
        t = setVal(pos, val, 2 * v + 1, m + 1, r);
    if (t)
        tree[v] = (tree[2 * v] | tree[2 * v + 1]);
    else
        tree[v] = (tree[2 * v] ^ tree[2 * v + 1]);
    return !t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < (1 << n); i++)
    {
        scanf("%d", &a[i]);
        setVal(i, a[i], 1, 0, (1 << n) - 1);
    }
    for (int i = 0; i < m; i++)
    {
        int p, b;
        scanf("%d%d", &p, &b);
        setVal(p - 1, b, 1, 0, (1 << n) - 1);
        printf("%d\n", tree[1]);
    }

    return 0;
}