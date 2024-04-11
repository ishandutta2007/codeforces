#include<bits/stdc++.h>
using namespace std;

string s[1001];
int m, n, o[1001];
map <string, int> p, t;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i] >> o[i];
        p[s[i]] += o[i];
    }
    for (int i = 0; i < n; i++){
        m = max(m, p[s[i]]);
    }
    int i;
    for (i = 0; p[s[i]] < m || (t[s[i]] += o[i]) < m; i++);
    cout << s[i];
}