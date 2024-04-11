#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;
int cnt;
vector <int> ali, bob, nah;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "11") ans += x, ++cnt;
        else if (s == "00") nah.push_back(x);
        else if (s == "01") bob.push_back(x);
        else if (s == "10") ali.push_back(x);
    }
    sort(ali.begin(), ali.end());
    sort(bob.begin(), bob.end());
    while (ali.size() && bob.size()) {
        ans += ali.back() + bob.back();
        ali.pop_back();
        bob.pop_back();
    }
    for (auto x: ali) nah.push_back(x);
    for (auto x: bob) nah.push_back(x);
    sort(nah.begin(), nah.end());
    while (cnt && nah.size()) --cnt, ans += nah.back(), nah.pop_back();
    cout << ans << endl;
    return 0;
}