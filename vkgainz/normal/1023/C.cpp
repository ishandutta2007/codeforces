#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 1e6+5;
vector<int> adj[MX], rev[MX];

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int curr = 0;
    string ans = "";
    for(int i = 0; i < k; i++) {
        if(curr == k - i) {
            ans += ')';
            --curr;
        }
        else {
            ans += s[i];
            if(s[i] == '(') 
                ++curr;
            else
                --curr;
        }
    }
    cout << ans << "\n";
}