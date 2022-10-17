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
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 5e6 + 10;
int arr[N];
vector<bool> prime(N, 1);
_ int get(int a) {
    if (prime[a]) {
        return 1;
    }
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            a /= i;
            break;
        }
    }
    return arr[a] + 1;
}

_ void source() {
    int lim = 5e6;
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= lim; i++) {
        if (prime[i]) {
            if (i * 1LL * i > lim) {
                continue;
            }
            for (int j = i * i; j <= lim; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= lim; i++) {
        arr[i] = get(i);
    }
    vector<int> pref(N);
    pref[0] = 0;
    for (int i = 1; i <= lim; i++) {
        pref[i] = pref[i - 1] + arr[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> r >> l;
        cout << pref[r] - pref[l] << endl;
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
    srand(time(0));
    source();
    return 0;
}