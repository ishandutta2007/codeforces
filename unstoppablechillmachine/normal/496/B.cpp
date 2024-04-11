#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long double PI = acos(-1);

_ void source() {
    string s, ans;
    queue<string> q;
    map<string, bool> used;
    cin >> s >> s;
    ans = s;
    used[s] = true;
    q.push(s);
    while (!q.empty()) {
        string s = q.front();
        ans = min(ans, s);
        q.pop();
        string s2 = s;
        char ch = s2[0];
        s2.ers(s2.begin());
        s2 += ch;
        if (!used[s2]) {
            used[s2] = true;
            q.push(s2);
        }
        for (int i = 0; i < s.size(); i++)  {
            if (s[i] == '9') {
                s[i] = '0';
            }
            else {
                s[i]++;
            }
        }
        if (!used[s]) {
            used[s] = true;
            q.push(s);
        }
        //cout << s << ' ' << s2 << endl;
    }
    cout << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    source();
    return 0;
}