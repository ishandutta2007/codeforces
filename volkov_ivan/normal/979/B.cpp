#include <iostream>
#include <map>

using namespace std;

int check(string s, int n) {
    if (s.length() == 1) return 0;
    map <char, int> cnt;
    for (int i = 0; i < s.length(); i++) cnt[s[i]]++;
    int max_ans = 0;
    int len = s.length();
    for (pair <char, int> elem : cnt) {
        if (n <= len - elem.second) max_ans = max(max_ans, elem.second + n);
        else {
            if (n == 1) max_ans = len - 1;
            else return len;
        }
    }
    return max_ans;
}

int main() {
    int n;
    string s1, s2, s3;
    cin >> n >> s1 >> s2 >> s3;
    int c1, c2, c3;
    c1 = check(s1, n);
    c2 = check(s2, n);
    c3 = check(s3, n);
    if (c1 > c2 && c1 > c3) {
        cout << "Kuro" << endl;
        return 0;
    }
    if (c2 > c1 && c2 > c3) {
        cout << "Shiro" << endl;
        return 0;
    }
    if (c3 > c1 && c3 > c2) {
        cout << "Katie" << endl;
    } else {
        cout << "Draw" << endl;
    }
    return 0;
}