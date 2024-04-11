#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    int n[k];
    vector <int> now;
    map <int, pair <int, int> > dict;
    for (int i = 0; i < k; i++) {
        cin >> n[i];
        int summ = 0;
        now.resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> now[j];
            summ += now[j];
        }
        for (int j = 0; j < n[i]; j++) {
            if (dict.find(summ - now[j]) != dict.end()) {
                cout << "YES" << endl;
                cout << dict[summ - now[j]].first << ' ' << dict[summ - now[j]].second << endl;
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
        for (int j = 0; j < n[i]; j++) {
            dict[summ - now[j]] = make_pair(i + 1, j + 1);
        }
    }
    cout << "NO" << endl;
    return 0;
}