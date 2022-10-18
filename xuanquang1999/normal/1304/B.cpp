#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, m;
string s[MAXN];

bool isPalindrome(string s) {
    for(int i = 0, j = s.length() - 1; i < j; ++i, --j)
        if (s[i] != s[j])
            return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
        cin >> s[i];

    string ansL, ansMid;

    for(int i = 0; i < n; ++i) {
        if (isPalindrome(s[i]))
            ansMid = s[i];
        else {
            for(int j = i+1; j < n; ++j) {
                string tmp = s[j];
                reverse(tmp.begin(), tmp.end());
                if (tmp == s[i]) {
                    ansL += s[i];
                    break;
                }
            }
        }
    }

    string ansR = ansL;
    reverse(ansR.begin(), ansR.end());
    string ans = ansL + ansMid + ansR;

    printf("%d\n", ans.size());
    cout << ans << endl;

    return 0;
}