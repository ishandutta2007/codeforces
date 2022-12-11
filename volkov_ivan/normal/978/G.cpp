#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int s[m], d[m], c[m];
    map <int, int> dict;
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> d[i] >> c[i];
        s[i]--;
        d[i]--;
        dict[d[i]] = i;
    }
    int ans[n];
    set <pair <int, int> > now;
    set <int> done;
    for (int i = 0; i < n; i++) {
        bool br = 0;
        for (int j = 0; j < m; j++) {
            if (d[j] == i) {
                if (done.find(d[j]) == done.end())  {
                    cout << "-1" << endl;
                    return 0;
                }
                ans[i] = m;
                br = 1;
            }
        }
        for (int j = 0; j < m; j++) {
            if (s[j] == i) now.insert(make_pair(d[j], c[j]));
        }
        if (br) continue;
        if (now.empty()) {
            ans[i] = -1;
            continue;
        }
        //cout << i << ' ' << (*now.begin()).first << endl;
        //cout << 42 << endl;
        ans[i] = dict[(*now.begin()).first];
        pair <int, int> nnew = *now.begin();
        nnew.second--;
        now.erase(*now.begin());
        now.insert(nnew);
        if ((*now.begin()).second == 0) {
            done.insert((*now.begin()).first);
            now.erase(*now.begin());
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << ' ';
    }
    return 0;
}