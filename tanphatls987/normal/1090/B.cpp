#include <bits/stdc++.h>

using namespace std;

const string sref = "\\begin{thebibliography}{99}";
const string refend = "\\end{thebibliography}";
vector<string> bib;
string test;


map<string, int> matest, mabib;
vector<string> ans;
int main() {

    while (1) {
        string s;
        getline(cin, s);
        if (s == sref) break;
        test = test + s;
    }

    while (1) {
        string s;
        getline(cin, s);
        if (s == refend) break;
        bib.push_back(s);
    }
    
    for(int j = 0; j < test.length() - 5; j++) 
        if (test.substr(j, 5) == "\\cite") {
            int st = j + 6;
            int en = st;
            while (test[en] != '}') en++;

            string name = test.substr(st, en - st);
            //cout << name << '\n';
            if (!matest[name]) {
                matest[name] = 1;
                ans.push_back(name);
            }
        }
    
    for(int i = 0; i < bib.size(); i++) {
        int st = 9, en = st;
        while (bib[i][en] != '}') en++;
        mabib[bib[i].substr(st, en - st)] = i;
    }

    bool correct = 1;
    for(int i = 0; i < ans.size(); i++) 
        correct &= mabib[ans[i]] == i;
    if (correct) {
        cout << "Correct";
        return 0;
    }
    cout << "Incorrect\n";
    cout << sref << '\n';
    for(int i = 0; i < ans.size(); i++) {
        cout << bib[mabib[ans[i]]] << '\n';
    }

    cout << refend << '\n';
}