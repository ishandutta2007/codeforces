#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef unsigned long long ull;

ull x = 0;
ull nxt() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
const int maxn = 100005;
int a[maxn], b[maxn];
void init(int n, int d) {
    for(int i = 0; i < n; i = i + 1) {
        a[i] = i;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[nxt() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[nxt() % (i + 1)]);
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, d;
    cin >> n >> d >> x;
    init(n, d);
    vector<int> p(n);
    for(int i = 0; i < n; ++i) {
        p[a[i]] = i;
    }
    const int K = 200;
    vector<int> pos;
    for(int i = 0; i < n; ++i) {
        if(b[i]) pos.push_back(i);
    }
    if(d <= K) {
        vector<int> ans(n, -1);
        for(int i = 0; i < n; ++i) {
            for(int j : pos) {
                if(i + j < n) {
                    ans[i + j] = max(ans[i + j], a[i]);
                }
            }
        }
        for(int i : ans) cout << i + 1 << "\n";
    } else {
        vector<int> ans(n, -1);
        for(int i = n - 1; i >= n - K + 1; --i) {
            int k = p[i];
            for(int j : pos) {
                if(k + j < n) {
                    ans[k + j] = max(ans[k + j], a[k]);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if(ans[i] == -1) {
                for(int j : pos) {
                    if(j <= i) {
                        ans[i] = max(ans[i], a[i - j]);
                    }
                }
                cout << ans[i] + 1 << "\n";
            } else {
                cout << ans[i] + 1 << "\n";
            }
        }
    }
}