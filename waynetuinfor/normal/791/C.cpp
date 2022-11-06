#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
vector<string> name;
int num[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    name.push_back("A"), name.push_back("B");
    for (int i = 0; i < 26; ++i) name.push_back(name[0] + (char)(i + 'a')), name.push_back(name[1] + (char)(i + 'a'));
    int n, k; cin >> n >> k;
    for (int i = 0; i < k - 1; ++i) num[i] = i;
    for (int i = k - 1; i < n; ++i) {
        string s; cin >> s;
        if (s == "YES") num[i] = i;
        else num[i] = num[i - k + 1];
    }
    for (int i = 0; i < n; ++i) cout << name[num[i]] << ' ';
    return cout << '\n', 0;
}