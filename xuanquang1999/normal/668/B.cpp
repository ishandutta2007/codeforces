#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
#define maxN 1000005
#define oo 1000000007

ll delta[2], n, q;
int ans[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> q;
    fto(i, 0, 1) delta[i] = i;
    fto(i, 1, q) {
        int t;
        scanf("%d", &t);
        if (t == 2) {
            fto(i, 0, 1) delta[i] ^= 1;
        }
        else {
            int x;
            scanf("%d", &x);
            fto(i, 0, 1) delta[i] += x;
        }
//        fto(i, 0, 1) printf("%d ", delta[i]);
//        puts("");
    }
    fto(i, 0, n-1) {
        ans[(n*(q+1)+delta[i%2]+i-i%2)%n] = i+1;
    }
    fto(i, 0, n-1) printf("%d ", ans[i]);


    return 0;
}