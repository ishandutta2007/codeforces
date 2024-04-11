#include <bits/stdc++.h>
using namespace std;

int req[10];
int poc[10];

int main() {
    int T;
    cin >> T;
    while(T > 0) {
        req[T%10]++;
        T /=10;}
    string s;
    cin >> s;
    for(int i =0; i < s.length(); i++) poc[s[i]-'0']++;
    poc[9] +=poc[6];
    poc[2] +=poc[5];
    req[9] +=req[6];
    req[2] +=req[5];
    int ans =s.length();
    for(int i =0; i < 10; i++) if(i < 5 || i > 6)
        if(req[i] > 0) ans =min(ans,poc[i]/req[i]);
    cout << ans << "\n";
    return 0;}