 #include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ll long long
#define ff first
#define ss second
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define maxN 5005
#define MOD 1000000007

struct tree {
    int id;
    double x;
    inline bool operator < (const tree &b) const {
        return (x < b.x);
    }
};

int n, m, f[maxN];
tree a[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);

    fto(i, 1, n) {
        scanf("%d%lf", &a[i].id, &a[i].x);
    }

    sort(a+1, a+n+1);

    fto(i, 1, n) {
        f[i] = 1;
        fto(j, 1, i-1) {
            if (a[j].id <= a[i].id) f[i] = max(f[i], f[j]+1);
        }
    }

    cout << n-*max_element(f+1, f+n+1);

    return 0;
}