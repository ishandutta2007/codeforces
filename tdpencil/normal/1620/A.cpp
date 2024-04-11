#include <bits/stdc++.h>

#define ar array
#define ll long long
#define pb push_back

using namespace std;
constexpr int mxN=1e4;
int n, m;
string labels[mxN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        // always possible unless two things
        // s[0] == E and s[n - 1] == N where s[0]..s[n-2] == E
        // actually always possible unless there is 1 N
        // yeah i think thats it
        if(count(s.begin(), s.end(), 'N') == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}