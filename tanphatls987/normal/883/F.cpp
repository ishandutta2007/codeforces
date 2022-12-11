#include <bits/stdc++.h>

using namespace std;

set <string> T;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        string str;
        for (int j = 0; j < s.size(); ++j)
            if (s[j] == 'u')
                str.push_back('o'), str.push_back('o');
            else
                str.push_back(s[j]);
        s = "";
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == 'h') {
                while (s.size() > 0 && s.back() == 'k')
                    s.pop_back();
            }
            s.push_back(str[j]);
        }
        T.insert(s);
    }
    cout << T.size() << "\n";
    return 0;
}