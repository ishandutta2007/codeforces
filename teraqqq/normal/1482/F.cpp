#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e5+7;

int n, k, p[N];
string s, ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    ans.reserve(k);
    cin >> s;

    for (int i = 0; ans.size() < k; ) {

        if (i == n || s[i] > s[p[i]]) i = p[i];
        ans.push_back(s[i]);
        if (i != 0) p[i + 1] = s[i] == s[p[i]] ? p[i] + 1 : 0;
        i += 1;
    }

    cout << ans << endl;
}