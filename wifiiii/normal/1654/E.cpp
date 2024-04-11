#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100000;
int cnt[200005];

template <typename T>
struct hash_table {
    static const int N = 10000121;
    int head[N], nxt[N], tm[N], tmcnt = 1, tot = 0;
    ll key[N];
    T val[N];
    hash_table() {
        memset(tm, 0, sizeof(tm));
    }
    void clear() {
        tot = 0;
        tmcnt++;
    }
    bool count(ll k) {
        int x = k % N; if(x < 0) x += N;
        if(tm[x] != tmcnt) return 0;
        for(int i = head[x]; ~i; i = nxt[i]) {
            if(key[i] == k) return 1;
        }
        return 0;
    }
    T & operator [](ll k) {
        int x = k % N; if(x < 0) x += N;
        if(tm[x] != tmcnt) tm[x] = tmcnt, head[x] = -1;
        for(int i = head[x]; ~i; i = nxt[i]) {
            if(key[i] == k) return val[i];
        }
        nxt[tot] = head[x], head[x] = tot, key[tot] = k, val[tot] = T();
        return val[tot++];
    }
};
hash_table<int> mp;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int mx = 0;
    const int K = 501;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < min(i + K, n); ++j) {
            if((a[j] - a[i]) % (j - i) == 0) {
                mx = max(mx, ++cnt[N + (a[j] - a[i]) / (j - i)]);
            }
        }
        for(int j = i + 1; j < min(i + K, n); ++j) {
            if((a[j] - a[i]) % (j - i) == 0) {
                --cnt[N + (a[j] - a[i]) / (j - i)];
            }
        }
    }
    mx += 1;
    const int P = 202;
    for(int k = -P; k <= P; ++k) {
        mp.clear();
        for(int i = 0; i < n; ++i) {
            mx = max(mx, ++mp[a[i] + k * i]);
        }
    }
    cout << n - mx << '\n';
}