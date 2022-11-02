#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    long long ans[26] = {};
//    for (int i = 0; i < 26; i++)
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        mp[s[i]] = i;
        vector<int> v;
        for (map<char, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
            v.push_back(it->second);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            int nxt = i < (int)v.size() - 1 ? v[i + 1] : (int)s.length();
            ans[i] += (nxt - v[i]);
        }
    }
    vector<long long> a;
    for (int i = 0; i < 26; i++)
        if (ans[i])
            a.push_back(ans[i]);
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
}