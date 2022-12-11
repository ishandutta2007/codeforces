#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
int main() {
    cin >> n >> k >> s;
    string old = s;
    for(int st = 0; st < k; st++)
        for(int i = st; i < n; i += k) s[i] = s[st];
    if (s < old) {
        int cur = k - 1;
        while (s[cur] == '9') cur--;
        s[cur]++;
        fill(s.begin() + cur + 1, s.begin() + k, '0');
    }
    for(int st = 0; st < k; st++)
        for(int i = st; i < n; i += k) s[i] = s[st];
    assert(s >= old);
    cout << n << '\n' << s;
}