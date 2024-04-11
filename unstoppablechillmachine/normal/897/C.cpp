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
#define int ll
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

const int N = 1e5 + 10;

int k, len[N];
string str, s;

_ char solve(int num, int cnt) {
    if (num == 0) {
        for (int i = 0; i < s.size(); i++) {
            cnt--;
            if (!cnt) {
                return s[i];
            }
        }
        return '.';
    }
    int al = 0;
    for (int i = 0; i < k; i++) {
        cnt--;
        if (!cnt) {
            return str[i];
        }
        if (str[i] == '"') {
            al++;
            if (al & 1) {
                if (len[num - 1] >= cnt) {
                    return solve(num - 1, cnt);
                }
                else {
                    cnt -= len[num - 1];
                }
            }
        }
    }
    return '.';
}

_ void source() {
    s = "What are you doing at the end of the world? Are you busy? Will you save us?",
    str = "What are you doing while sending ";
    str += '"';str += '"';
    str += "? Are you busy? Will you send ";
    str += '"';str += '"';str += '?';
    k = str.size();
    //cout << str << endl;
    len[0] = 75;
    for (int i = 1; i <= 1e5; i++) {
        len[i] = k + 2 * len[i - 1];
        len[i] = min(len[i], BINF);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b);
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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