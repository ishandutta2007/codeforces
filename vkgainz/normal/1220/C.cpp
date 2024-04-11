#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s; cin >> s;
    set<int> r;
    for(int i=0;i<s.length();i++){
        r.insert(s[i]-'a');
        auto it = r.begin();
        if(s[i]-'a'==(*it))
            cout << "Mike" << endl;
        else
            cout << "Ann" << endl;
    }
}