#include <bits/stdc++.h>
using namespace std;

int main() {
    string t; cin >> t;
    int n = (int)t.size();
    vector<int> v(n), p(n), rev(n);;
    for (int i = 0; i < n; ++i) v[i] = i;
    int f = 1;
    for (int i = 0; i < 3; ++i) {
        string s = "";
        for (int j = 0; j < n; ++j) {
            s += (char)(v[j] % 26 + 'a'); 
            v[j] /= 26;
        }
        cout << "? " << s << endl;
        string res; cin >> res;
        for (int j = 0; j < n; ++j) p[j] += f * (res[j] - 'a');
        f *= 26;
    }
    for (int i = 0; i < n; ++i) rev[p[i]] = i;
    cout << "! ";
    for (int i = 0; i < n; ++i) cout << t[rev[i]];
    cout << endl;
}