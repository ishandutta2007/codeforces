#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); ++it)
#define ll long long
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 100005
#define oo 1000000007

int n, a[maxN], moveCnt, colCnt;
bool collected[maxN];
vector<int> res;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    while (true) {
        fto(i, 1, n)
            if (!collected[i] && colCnt >= a[i]) {
                collected[i] = true;
                ++colCnt;
            }
        if (colCnt == n) break;
        ++moveCnt;

        fdto(i, n, 1)
            if (!collected[i] && colCnt >= a[i]) {
                collected[i] = true;
                ++colCnt;
            }
        if (colCnt == n) break;
        ++moveCnt;
    }

    cout << moveCnt;

    return 0;
}