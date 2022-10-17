#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// cp-algorithms
// source: https://cp-algorithms.com/string/prefix-function.html#building-an-automaton-according-to-the-prefix-function

vector<int> pi;
string s;

void extend(){
    int i = pi.size();
    pi.push_back(0);
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j])
        j = pi[j-1];
    if (s[i] == s[j])
        j++;
    pi[i] = j;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    pi = {0};
    for (int i = 1; i < s.size(); ++i){
        extend();
    }
    unordered_map<string, int> mp;
    int Q; cin >> Q;
    while (Q--){
        string t; cin >> t;
        s += t;
        for (int i = 0; i < t.size(); ++i){
            string sub = t.substr(0, i+1);
            if (mp.count(sub)) pi.push_back(mp[sub]);
            else{
                extend();
                mp[sub] = pi.back();
            }
            cout << pi.back() << " ";
        }
        cout << '\n';
        for (char c : t){
            pi.pop_back();
            s.pop_back();
        }
    }
}