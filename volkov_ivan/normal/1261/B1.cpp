#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct query{
    int pos, num;
    query() {}
    query(int pos, int num): pos(pos), num(num) {}
};

const int N = 1 << 18;
int t[2 * N], arr[N], ans[N];
pair <int, int> a[N];
vector <query> q[N];

void relax(int pos) {
    t[pos] = t[2 * pos] + t[2 * pos + 1];
}

void update(int pos) {
    pos += N - 1;
    t[pos]++;
    while (pos > 1) {
        pos /= 2;
        t[pos]++;
    }
}

int find_kth(int pos, int l, int r, int k) {
    if (l == r) return arr[l];
    int m = (l + r) / 2;
    if (t[2 * pos] >= k) return find_kth(2 * pos, l, m, k);
    return find_kth(2 * pos + 1, m + 1, r, k - t[2 * pos]);
}

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first != b.first) return (a.first > b.first);
    return (a.second < b.second);
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k, pos;
        cin >> k >> pos;
        q[k].push_back(query(pos, i));
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        update(a[i].second);
        arr[a[i].second] = a[i].first;
        for (query elem : q[i]) {
            ans[elem.num] = find_kth(1, 1, N, elem.pos);
        }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
    return 0;
}