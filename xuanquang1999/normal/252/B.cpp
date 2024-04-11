using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005

int a[maxN], n;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    bool ok = true;
    fto(i, 1, n-1)
        if (a[i-1] != a[i]) {
            ok = false;
            break;
        }
    if (ok) {
        printf("-1");
        return 0;
    }

    fto(i, 0, n-2)
        fto(j, i+1, n-1)
            if (a[i] != a[j]) {
                swap(a[i], a[j]);

                bool ok;
                if (a[0] >= a[1]) {
                    ok = true;
                    fto(k, 2, n-1)
                        if (a[k-1] < a[k]) {
                            ok = false;
                            break;
                        }
                    if (ok) {
                        swap(a[i], a[j]);
                        continue;
                    }
                }
                if (a[0] <= a[1]) {
                    ok = true;
                    fto(k, 2, n-1)
                        if (a[k-1] > a[k]) {
                            ok = false;
                            break;
                        }
                    if (ok) {
                        swap(a[i], a[j]);
                        continue;
                    }
                }

                printf("%d %d\n", i+1, j+1);
                return 0;
            }

    printf("-1");

    return 0;
}