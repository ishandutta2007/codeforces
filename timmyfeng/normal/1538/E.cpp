#include <bits/stdc++.h>
using namespace std;

int count(string s) {
    int ans = 0;
    for (int i = 0; i + 4 <= (int) s.size(); ++i) {
        ans += s.substr(i, 4) == "haha";
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string var;
        map<string, tuple<long long, string, string>> value;
        while (n--) {
            string symbol;
            cin >> var >> symbol;

            if (symbol == ":=") {
                string literal;
                cin >> literal;

                value[var] = {
                    count(literal),
                    literal.size() > 3 ? literal.substr(0, 3) : literal,
                    literal.size() > 3 ? literal.substr(literal.size() - 3) : literal
                };
            } else {
                string left, right;
                cin >> left >> symbol >> right;

                string prefix = get<1>(value[left]) + get<1>(value[right]);
                string suffix = get<2>(value[left]) + get<2>(value[right]);

                value[var] = {
                    get<0>(value[left]) + get<0>(value[right]) + count(get<2>(value[left]) + get<1>(value[right])),
                    prefix.size() > 3 ? prefix.substr(0, 3) : prefix,
                    suffix.size() > 3 ? suffix.substr(suffix.size() - 3) : suffix
                };
            }
        }

        cout << get<0>(value[var]) << "\n";
    }
}