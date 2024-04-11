#include <iostream>
#include <set>
#include <map>
 
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set <int> intr, extr;
    map <int, int> dict;
    int n;
    cin >> n;
    int w[n], ans[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        intr.insert(w[i]);
        dict[w[i]] = i + 1;
    }
    string s;
    cin >> s;
    int best;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '0') {
            best = *intr.begin();
            intr.erase(best);
            ans[i] = best;
            extr.insert(-best);
        } else {
            best = *extr.begin();
            extr.erase(best);
            best = -best;
            ans[i] = best;
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        cout << dict[ans[i]] << ' ';
    }
    return 0;
}