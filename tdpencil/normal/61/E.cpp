#include <bits/stdc++.h>
using namespace std;

#define int long long
// a * b = x * y
// find factors of x * y

// first coordinate comrpess
// use fenwick tree to find inversions
// then use another fenwick tree to find inversions related to inversions


const int MAXN = 1e6;
int N;
int A[MAXN], B[MAXN], ft1[MAXN + 1], ft2[MAXN + 1];
int inversions[MAXN];
pair<int, int> coordinateCompress[MAXN];

void update(int *ft, int pos, int val) {
    for(++pos; pos <= MAXN; pos += pos & -pos)
        ft[pos] += val;
}
int get(int *ft, int pos) {
    int sum =0;
    for(++pos; pos > 0; pos -= pos & -pos)
        sum += ft[pos];
    return sum;
}
int query(int *ft, int l, int r) {
    return (l==0?get(ft, r):get(ft, r)-get(ft, l - 1));
}
void run_case() {
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];


    for(int i = 0; i < N; i++)
        B[i] = A[i];

    sort(B, B + N);
    for(int i = 0; i < N; i++)
        coordinateCompress[i] = pair<int, int>{B[i], i};

    auto getpos=[&](int val) -> int {
        return (*lower_bound(coordinateCompress, coordinateCompress + N, pair<int, int>{val, 0})).second;
    };

    for(int i = 0; i < N; i++) {
        // vals less than a[i]
        inversions[i] = query(ft1, getpos(A[i]), MAXN - 1);
        update(ft1, getpos(A[i]), 1);
    }
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        // cout << inversions[i] << "\n";
        long long res = query(ft2, getpos(A[i]), MAXN - 1);
        update(ft2, getpos(A[i]), inversions[i]);
        ans += res;
    }

    cout << ans << "\n";

}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

#ifdef RUN_CASE
    cin >> T;
#endif

    for(int test_case = 0; test_case < T; test_case++)
        run_case();
}