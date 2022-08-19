#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1 << 17;
const int INF = (int)1e8;

struct Node
{
    int l, r;
    pii val;

    Node() : l(-1), r(-1), val(INF, INF) {}
    Node(int _l, int _r) : l(_l), r(_r), val(mp(INF, _l)) {}
};
Node tree[2 * N];

int fenv[N];
void fenvAdd(int p, int d)
{
    for(; p < N; p |= p + 1)
        fenv[p] += d;
}
int fenvGet(int r)
{
    int res = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1)
        res += fenv[r];
    return res;
}

void buildTree()
{
    for (int i = 0; i < N; i++)
        tree[N + i] = Node(i, i + 1);
    for (int i = N - 1; i > 0; i--)
        tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void treeSet(int v, int val)
{
    v += N;
    tree[v].val.first = val;
    while(v > 1) {
        v >>= 1;
        tree[v].val = min(tree[2 * v].val, tree[2 * v + 1].val);
    }
}
pii treeGet(int v, int l, int r)
{
    if (l <= tree[v].l && tree[v].r <= r)
        return tree[v].val;
    if (l >= tree[v].r || tree[v].l >= r)
        return mp(INF, INF);
    return min(treeGet(2 * v, l, r), treeGet(2 * v + 1, l, r));
}

int n;
int a[N];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    buildTree();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        treeSet(i, a[i]);
    }
    for (int i = 0; i < n; i++)
        fenvAdd(i, 1);
    sort(a, a + n);
    ll ans = 0;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        pii m = treeGet(1, pos, n);
        if (m.first != a[i]) {
            ans += n - i - fenvGet(pos - 1);
            pos = 0;
            m = treeGet(1, pos, n);
        }
        if (m.first != a[i]) throw;
        if (m.second < pos) throw;
        ans += fenvGet(m.second) - fenvGet(pos - 1);
        pos = m.second;
        treeSet(pos, INF);
        fenvAdd(pos, -1);
        //printf("%d\n", pos);
    }
    printf("%lld\n", ans);

    return 0;
}