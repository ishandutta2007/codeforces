#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int maxn = 3e5 + 1;
int h[maxn], dp[maxn], lge[maxn], lle[maxn], rge[maxn], rle[maxn];
vector<int>jumps[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        dp[i] = INF;
    }
    dp[0] = 0;
    vector<pair<int, int> >st;
    for (int i = 0; i < n; i++) { // the nearest greater from the left
        while (!st.empty() && st.back().first < h[i]) {
            st.pop_back();
        }
        if (st.empty()) lge[i] = -1;
        else lge[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = 0; i < n; i++) { // the nearest less from the left
        while (!st.empty() && st.back().first > h[i]) {
            st.pop_back();
        }
        if (st.empty()) lle[i] = -1;
        else lle[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) { // the nearest greater from the right
        while (!st.empty() && st.back().first < h[i]) {
            st.pop_back();
        }
        if (st.empty()) rge[i] = -1;
        else rge[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) { // the nearest less from the right
        while (!st.empty() && st.back().first > h[i]) {
            st.pop_back();
        }
        if (st.empty()) rle[i] = -1;
        else rle[i] = st.back().second;
        st.push_back({h[i], i});
    }
    st.clear();
    for (int i = 0; i < n; i++) {
        if (rle[i] != -1) jumps[i].push_back(rle[i]);
        if (rge[i] != -1) jumps[i].push_back(rge[i]);
        if (lle[i] != -1) jumps[lle[i]].push_back(i);
        if (lge[i] != -1) jumps[lge[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        for (int to : jumps[i]) {
            dp[to] = min(dp[to], dp[i] + 1);
        }
    }
    cout << dp[n - 1];
    return 0;
}