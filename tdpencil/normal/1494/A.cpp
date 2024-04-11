#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    auto bracketSequence = [&](string t) {
        stack<char> c;
        c.push(t[0]);
        for(int i = 1; i < int(t.size()); i++) {
            char e = t[i];
            if(!c.empty() && e == ')' && c.top() == '(') {
                c.pop();
            } else {
                c.push(e);
            }
        }
        return c.size() == 0;
        
    };
    int T = 1;
    cin >> T;
    for(int case_num = 1; case_num <= T; case_num++) {
        string s;
        cin >> s;
        bool works = false;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    char choice1 = i&1?'(':')';
                    char choice2 = j&1?'(':')';
                    char choice3 = k&1?'(':')';
                    string t;
                    for(auto &e: s) {
                        if(e == 'A') t += choice1;
                        if(e == 'B') t += choice2;
                        if(e == 'C') t += choice3;
                    }
                    works |= bracketSequence(t);
                }
            }
        }
        cout << (works ? "YES" : "NO") << "\n";

    }
}