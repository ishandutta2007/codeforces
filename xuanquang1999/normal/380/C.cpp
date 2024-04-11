//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 1000005
#define oo 1000000007
#define EPS 10e-9

struct NodeType {
    int a, b, c;
};

int a[maxN], m, n;
char s[maxN];
NodeType IT[4*maxN], nullNode;

NodeType combine (const NodeType &x, const NodeType &y) {
    NodeType res;
    int t = min(x.b, y.c);
    res.a = x.a + y.a + 2*t;
    res.b = x.b + y.b - t;
    res.c = x.c + y.c - t;
    return res;
}

void build(int root, int left, int right) {
    if (left == right) {
        IT[root].a = 0;
        if (s[left] == '(') IT[root].b = 1, IT[root].c = 0;
        else IT[root].b = 0, IT[root].c = 1;
    }
    else {
        int mid = (left+right)/2;
        build(2*root, left, mid);
        build(2*root+1, mid+1, right);
        IT[root] = combine(IT[2*root], IT[2*root+1]);
    }
}

NodeType query(int root, int left, int right, int i, int j) {
    if (i > right || j < left) return nullNode;
    if (i <= left && right <= j) return IT[root];
    int mid = (left+right)/2;
    return combine(query(2*root, left, mid, i, j), query(2*root+1, mid+1, right, i, j));
}

int main() {
    scanf("%s", s); n = strlen(s);
    build(1, 0, n-1);
    scanf("%d", &m);
    fto(i, 1, m) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, 0, n-1, l-1, r-1).a);
    }

    return 0;
}