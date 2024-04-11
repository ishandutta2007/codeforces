#include <iostream>
#include <string>

using namespace std;

int t;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    for(cin >> t; t--;) {
        cin >> s;
        bool is_p = true;
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
            if(s[i] != s[j]) is_p = false;

        if(is_p) {
            for(int i = 1; i < s.size(); ++i) {
                if(s[0] != s[i]) {
                    swap(s[0], s[i]); is_p=false;
                    break;
                }
            }
        }

        if(is_p) cout << -1 << endl;
        else cout << s << endl;
    }
}