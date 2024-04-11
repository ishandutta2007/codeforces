#include <bits/stdc++.h>


int main() {
    using namespace std;

    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int ans = 0;
    string s;
    cin >> s;
    stack<char> rbs;
    string opening = "{[(<"; 
    auto is_in = [&](char c) {
        return opening.find(c) != string::npos;
    };
    for(char ch : s) {
        if(is_in(ch)) {
            rbs.push(ch);
        } else {
            if(rbs.empty()) {
                cout << "Impossible\n";
                return 0;
            }
            string s; s += rbs.top();
            s += ch;
            if(!(s == "{}" || s == "[]" || s == "<>" || s == "()"))
                ans++;  
            rbs.pop();
        }
    }

    if(rbs.empty())
        cout << ans << "\n";
    else
        cout << "Impossible\n";

}