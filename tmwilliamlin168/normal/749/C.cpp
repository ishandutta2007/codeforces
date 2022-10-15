#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    queue<int> d, r;
    for(int i=0; i<n; ++i)
        if(s[i]=='D')
            d.push(i);
        else
            r.push(i);
    while(true) {
        if(d.empty()) {
            cout << "R";
            return 0;
        }
        if(r.empty()) {
            cout << "D";
            return 0;
        }
        if(d.front()<r.front())
            d.push(d.front()+n);
        else
            r.push(r.front()+n);
        d.pop();
        r.pop();
    }
}