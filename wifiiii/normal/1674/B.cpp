#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<string, int> mp;
    int cnt = 0;
    for(char a = 'a'; a <= 'z'; ++a) {
        for(char b = 'a'; b <= 'z'; ++b) {
            if(a != b) {
                mp[string(1, a) + b] = ++cnt;
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << mp[s] << '\n';
    }
}