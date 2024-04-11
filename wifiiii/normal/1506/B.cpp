#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int p = find(s.begin(), s.end(), '*') - s.begin();
        int e = find(s.rbegin(), s.rend(), '*') - s.rbegin();
        e = s.size() - 1 - e;
        s[p] = 'x';
        int last = p, last2 = p, ans = 1;
        for(int i = p + 1; i <= e; ++i) {
            if(i - last > k) {
                last = last2;
                s[last] = 'x';
                ++ans;
            }
            if(s[i] == '*') last2 = i;
        }
        if(s[e] == '*') ++ans;
        cout << ans << endl;
    }
}