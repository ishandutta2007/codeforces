#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

// https://codeforces.com/blog/entry/58316
template <typename T>
struct veniceset {
    multiset<T> S;
    T base = 0;
    void insert(T v) {
        S.insert(v - base);
    }
    void erase(T v) {
        S.erase(S.find(v - base));
    }
    void add(T v) {
        base += v;
    }
    T getmin() {
        return *S.begin() + base;
    }
    T getmax() {
        return *S.rbegin() + base;
    }
    size_t size() {
        return S.size();
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    veniceset<ll> s;
    for(int i = 0; i < n; ++i) {
        s.insert(a[i]);
        s.add(-b[i]);
        ll tmp = 1ll * s.size() * b[i];
        while(s.size() && s.getmin() < 0) {
            tmp -= abs(s.getmin());
            s.erase(s.getmin());
        }
        cout << tmp << " ";
    }
    cout << endl;
}