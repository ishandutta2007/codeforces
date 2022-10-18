//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1005
#define maxK 20
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int n, ans[maxN];

void Solve(int x, int y, int n) {

}

int main () {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) ans[i] = oo;

    int k = log2(n-1);
    fto(i, 0, k) {
        fto(b, 0, 1) {
            vector<int> ask;
            fto(j, 0, n-1) {
                if (((j>>i)&1)^b) ask.pb(j);
            }
            printf("%d\n", ask.size());
            forit(it, ask) printf("%d ", *it+1);
            //puts("");
            fflush(stdout);

            fto(j, 0, n-1) {
                int x;
                scanf("%d", &x);
                if (((j>>i)&1)^(1-b)) ans[j] = min(ans[j], x);
            }
        }
    }

    puts("-1");
    fto(i, 0, n-1) printf("%d ", ans[i]);
    fflush(stdout);

    return 0;
}