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
const int maxn = 200005;
int pref[maxn][26];
string s, t;
int main() {
    int n;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            pref[i + 1][j] = pref[i][j];
        }
        pref[i + 1][s[i] - 'a']++;
    }
    int q;
    cin >> q;
    while (q--) {
        cin >> t;
        vi nd(26);
        for (int i = 0; i < t.size(); i++) {
            nd[t[i] - 'a']++;
        }
        int bot = 1, top = n, ans = n;
        while (bot <= top) {
            int mid = bot + top >> 1;
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                ok &= (nd[i] <= pref[mid][i]);
            }
            if (ok) top = mid - 1, ans = mid;
            else bot = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}