#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, maxi = -1;
    string s, now, ans;
    cin >> n >> s;
    map <string, int> cnt;
    for (int i = 0; i < s.length() - 1; i++) {
        now = "";
        now += s[i];
        now += s[i + 1];
        cnt[now]++;
    }
    for (pair <string, int> elem : cnt) {
        if (elem.second > maxi) {
            maxi = elem.second;
            ans = elem.first;
        }
    }
    cout << ans << endl;
    return 0;
}