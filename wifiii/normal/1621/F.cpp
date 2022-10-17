#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        } else if(count(s.begin(), s.end(), '0') == n) {
            cout << a << '\n';
            continue;
        } else if(count(s.begin(), s.end(), '1') == n) {
            cout << b << '\n';
            continue;
        }
        vector<int> z;
        int x = 0, l = 0, r = 0;
        for(int i = 0, j; i < s.size(); ) {
            j = i;
            while(j < s.size() && s[i] == s[j]) ++j;
            if(s[i] == '1') {
                x += j - i - 1;
            } else {
                if(i == 0) l = j - i;
                else if(j == s.size()) r = j - i;
                else z.push_back(j - i - 1);
            }
            i = j;
        }
        sort(z.begin(), z.end());
        reverse(z.begin(), z.end());
        int y = 0;
        if(l) y += l - 1;
        if(r) y += r - 1;
        ll ans = 0;
        {
            int xx = x, yy = y; auto zz = z;
            ll res = 0;
            auto d0 = [&]() -> int {
                while(!z.empty()) {
                    if(z.back() == 0) {
                        z.pop_back();
                        res += max(0, b - c);
                    } else {
                        --z.back();
                        res += a;
                        return 1;
                    }
                }
                if(y) {
                    --y;
                    res += a;
                    return 1;
                }
                return 0;
            };
            if(d0()) {
                while(x) {
                    --x;
                    res += b;
                    if(!d0()) break;
                }
            }
            if(x) {
                if(b > c && l) {
                    --x;
                    res += b - c;
                }
            }
            if(x) {
                if(b > c && r) {
                    --x;
                    res += b - c;
                }
            }
            x = xx, y = yy, z = zz;
            ans = res;
        }
        {
            ll res = 0;
            auto d0 = [&]() -> int {
                while(!z.empty()) {
                    if(z.back() == 0) {
                        z.pop_back();
                        res += max(0, b - c);
                    } else {
                        --z.back();
                        res += a;
                        return 1;
                    }
                }
                if(y) {
                    --y;
                    res += a;
                    return 1;
                }
                return 0;
            };
            while(x) {
                --x;
                res += b;
                if(!d0()) break;
            }
            if(x) {
                if(b > c && l) {
                    --x;
                    res += b - c;
                }
            }
            if(x) {
                if(b > c && r) {
                    --x;
                    res += b - c;
                }
            }
            ans = max(ans, res);
        }
        cout << ans << '\n';
    }
}