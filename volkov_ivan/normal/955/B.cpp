#include <iostream>
#include <map>
 
using namespace std;

int main() {
    string s;
    cin >> s;
    map <char, int> cnt;
    for (int i = 0; i < s.length(); i++) {
        cnt[s[i]]++;
    }
    if (cnt.size() > 4) {
        cout << "No" << endl;
        return 0;
    }
    if (cnt.size() == 4) {
        cout << "Yes" << endl;
        return 0;
    }
    int cnt_big = 0;
    for (pair <char, int> elem : cnt) {
        if (elem.second > 1) cnt_big++;
    }
    if (cnt.size() == 3) {
        if (cnt_big != 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    if (cnt.size() == 2) {
        if (cnt_big == 2) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}