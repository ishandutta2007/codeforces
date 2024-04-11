#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int cnt[26];

bool check(int t) {
    for (int i = 0; i < t; ++i) if (cnt[i]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    stack<int> st;
    for (int i = 0; i < s.length(); ++i) ++cnt[s[i] - 'a'];
    for (int i = 0; i < s.length(); ++i) {
        while (st.size() && check(st.top())) cout << (char)(st.top() + 'a'), st.pop();
        st.push(s[i] - 'a'); --cnt[s[i] - 'a'];
    }
    while (st.size()) cout << (char)(st.top() + 'a'), st.pop(); cout << endl;
    return 0;
}