#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 2e5 + 7;
int f[N];
int pref[N];
int pos[N];
int res[2 * N];

void upd(int pos, int val) {
    for (int i = pos; i < N; i += i & (-i)) f[i] += val;
}

int get(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= i & (-i)) res += f[i];
    return res;
}

int find_nearest(int pos) {
    int left = 0, right = pos, mid;
    int need = get(pos);
    if (need == 0) return -1;
    while (right - left > 1) {
        mid = (left + right) / 2;
        if (get(mid) == need) right = mid;
        else left = mid;
    }
    return right;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(f, 0, sizeof(f));
    int n;
    cin >> n;
    vector <pair <char, int>> x(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        char c;
        cin >> c;
        if (c == '+') x[i] = make_pair('+', -1), upd(i, 1);
        else {
            int k;
            cin >> k;
            x[i] = make_pair('-', k);
            pos[k] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        int cur = find_nearest(pos[i]);
        //cout << i << ' ' << cur << endl;
        if (cur == -1) {
            //cout << 57 << endl;
            cout << "NO" << endl;
            return 0;
        }
        upd(cur, -1);
        res[cur] = i;
    }
    //cout << 65 << endl;
    set <int> have;
    vector <int> aans;
    for (int i = 1; i <= 2 * n; i++) {
        //cout << i << endl;
        //cout << i << ' ' << x[i].first << ' ' << x[i].second << endl;
        //return  0;
        if (x[i].first == '+') {
            have.insert(res[i]);  
            aans.push_back(res[i]);
        } else {
            auto l = *have.begin();
            have.erase(have.begin());
            if (l != x[i].second) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int elem : aans) {
        cout << elem << ' ';
    }
    cout << endl;
    return 0;
}