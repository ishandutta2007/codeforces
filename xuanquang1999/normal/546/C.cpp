using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define lli pair<long long, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define mod 1000000009
queue<int> a, b;
int n, k1, k2;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    scanf("%d", &k1);
    fto(i, 1, k1) {
        int x;
        scanf("%d", &x);
        a.push(x);
    }
    scanf("%d", &k2);
    fto(i, 1, k2) {
        int x;
        scanf("%d", &x);
        b.push(x);
    }

    fto(i, 0, 4000000) {
        if (a.empty()) {
            printf("%d 2", i);
            return 0;
        }
        if (b.empty()) {
            printf("%d 1", i);
            return 0;
        }
        int x = a.front(); a.pop();
        int y = b.front(); b.pop();
        if (x > y) {
            a.push(y); a.push(x);
        }
        if (x < y) {
            b.push(x); b.push(y);
        }
    }

    printf("-1");

    return 0;
}