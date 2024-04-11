#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int stk[100005], tp = 0;
int main() {
    string s;
    cin >> s;
    for(char c : s) {
        if(tp && stk[tp] == c) --tp;
        else stk[++tp] = c;
    }
    cout << (tp ? "No" : "Yes") << endl;
}