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
#define maxN 100005
#define maxB 20
#define oo 1000000007
#define EPS 10e-9

struct NodeType {
    int v, sum;
};

int a[maxN];

struct BitIT {
    bitset<maxN> a;
    NodeType T[4*maxN];

    void Synthesize (const int &root) {
        T[root].sum = T[2*root].sum + T[2*root+1].sum;
    }

    void Propagate(const int &root, const int &left, const int &right) {
        int mid = (left+right)/2;
        if (T[root].v != 0) {
            if (T[root].v & 1) {
                T[2*root].sum = (mid-left+1)-T[2*root].sum;
                T[2*root+1].sum = (right-mid)-T[2*root+1].sum;
            }
            T[2*root].v += T[root].v;
            T[2*root+1].v += T[root].v;
            T[root].v = 0;
        }
    }

    void Build(int root, int left, int right) {
        T[root].v = 0;
        if (left == right) T[root].sum = a[left];
        else {
            int mid = (left+right)/2;
            Build(2*root, left, mid);
            Build(2*root+1, mid+1, right);
            Synthesize(root);
        }
    }

    void Update(int root, int left, int right, int i, int j) {
        if (i > right || j < left) return;
        if (i <= left && right <= j) {
            T[root].v += 1;
            T[root].sum = (right-left+1)-T[root].sum;
            return;
        }
        Propagate(root, left, right);
        int mid = (left+right)/2;
        Update(2*root, left, mid, i, j);
        Update(2*root+1, mid+1, right, i, j);
        Synthesize(root);
    }

    int Query(int root, int left, int right, int i, int j) {
        if (i > right || j < left) return 0;
        if (i <= left && right <= j) return T[root].sum;
        Propagate(root, left, right);
        int mid = (left+right)/2;
        return Query(2*root, left, mid, i, j) + Query(2*root+1, mid+1, right, i, j);
    }
};

int n, q;
BitIT IT[maxB];

int main() {
    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(b, 0, maxB-1) {
        fto(i, 1, n) IT[b].a[i] = a[i] & (1<<b);
        IT[b].Build(1, 1, n);
    }

    scanf("%d", &q);
    fto(iq, 1, q) {
        int t, u, v, x;
        scanf("%d%d%d", &t, &u, &v);
        if (t == 1) {
            ll res = 0;
            fto(b, 0, maxB-1) res += (ll)IT[b].Query(1, 1, n, u, v)*(1<<b);
            printf("%I64d\n", res);
        }
        else {
            scanf("%d", &x);
            fto(b, 0, maxB-1) {
                if (x&(1<<b)) IT[b].Update(1, 1, n, u, v);
            }
        }
    }

    return 0;
}