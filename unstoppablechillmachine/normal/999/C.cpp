//I_l_M_P
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 5e5 + 10;
int left[N], right[N], first[26];
bool del[N];
vector<int> have[26];

_ void source() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s.ins(s.begin(), ' ');
    for (int i = 1; i <= n; i++) {
        right[i] = i + 1;
        left[i] = i - 1;
        if (!first[s[i] - 'a']) {
            first[s[i] - 'a'] = i;
        }
        have[s[i] - 'a'].pb(i);
    }
    for (int i = 0; i < 26; i++) {
        reverse(all(have[i]));
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 26; j++) {
            if (first[j]) {
                int pos = first[j];
                left[right[pos]] = left[pos];
                right[left[pos]] = right[pos];
                del[pos] = true;
                have[j].pop_back();
                if (have[j].empty()) {
                    first[j] = 0;
                }
                else {
                    first[j] = have[j].back();
                }
                break;
            }
        }
    }
    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (!del[i]) {
            start = i;
            break;
        }
    }
    while (start >= 1 && start <= n) {
        cout << s[start];
        start = right[start];
    }
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
    source();
    return 0;
}