#include <bits/stdc++.h>
using namespace std;
template<typename T>
long long merge_sort(vector<T>& v, vector<T>& aux, int l, int r) {
    if (r <= l) return 0LL;
    int m = l + (r - l) / 2;
    long long res = merge_sort(v, aux, l, m) + merge_sort(v, aux, m + 1, r);
    int x = l, y = m + 1, z = l;
    while (x <= m && y <= r) {
        aux[z++] = v[x] <= v[y] ? v[x++] : (res += m - x + 1, v[y++]);
    }
    while (x <= m) aux[z++] = v[x++];
    while (y <= r) aux[z++] = v[y++];
    while (l <= r) v[--z] = aux[r--];
    return res;
}
template<typename T>
long long inversions(vector<T> v) {
    static vector<T> aux;
    aux.resize(max(aux.size(), v.size()));
    return merge_sort(v, aux, 0, (int)v.size() - 1);
}
const long long inf = 0x3f3f3f3f3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        int cnt[2]{};
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            a[i] &= 1;
            ++cnt[a[i]];
        }
        long long ans = inf;
        for (int b : {0, 1}) {
            if (cnt[b] == (N + 1) / 2 && cnt[b ^ 1] == N / 2) {
                vector<int> pos(N);
                int ptr[2] = {b, b ^ 1};
                for (int i = 0; i < N; ++i) {
                    pos[i] = ptr[a[i]];
                    ptr[a[i]] += 2;
                }
                ans = min(ans, inversions(pos));
            }
        }
        if (ans == inf) ans = -1;
        cout << ans << '\n';
    }
    exit(0);
}