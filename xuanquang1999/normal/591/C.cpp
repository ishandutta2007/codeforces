using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 500005

int n, a[maxN], res[maxN], maxS;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    a[0] = a[n+1] = 2;
    fto(l, 1, n) {
        if (a[l-1] == a[l+1] && a[l-1] != a[l]) {
            int r;
            fto(i, l+1, n)
                if (a[i-1] != a[i+1]) {
                    r = i-1; break;
                }
//            debug(l);
//            debug(r);
            if ((r-l+1) % 2 == 0) {
                maxS = max(maxS, (r-l+1)/2);
                fto(i, l, (r+l)/2) res[i] = a[l-1];
                fto(i, (r+l)/2+1, r) res[i] = a[r+1];
            }
            else {
                maxS = max(maxS, (r-l)/2+1);
                fto(i, l, r) res[i] = a[l-1];
            }
            l = r;
        }
        else res[l] = a[l];
    }

    printf("%d\n", maxS);
    fto(i, 1, n) printf("%d ", res[i]);

    return 0;
}