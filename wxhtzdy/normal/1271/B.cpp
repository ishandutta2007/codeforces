#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 205;
int n;
string s;
char inv(char c) {
    return c ^ 'W' ^ 'B';
}
int main() {
    cin >> n >> s;
    for (char c : {'W', 'B'}) {
        string t = s;
        vi ans;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != c) {
                s[i] = inv(s[i]);
                s[i + 1] = inv(s[i + 1]);
                ans.pb(i);
            }
        }
        if (s[n - 1] != c) {
            s = t;
            continue;
        }
        printf("%d\n", ans.size());
        for (int i : ans) printf("%d ", i + 1);
        return 0;
    }
    printf("-1");
    return 0;
}