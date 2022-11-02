#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#ifdef OI_DEBUG
template<char endch, typename T>
void log_impl(T&& val) { cout << val << endch; }
template<char endch, typename T, typename... Ts>
void log_impl(T &&val, Ts &&...vals) {
    cout << val << ' ';
    log_impl<endch>(vals...);
}
#define logs log_impl<' '>
#define logln log_impl<'\n'>
#else
template<typename... Ts> void do_nothing(Ts &&...vals) {}
#define logs do_nothing
#define logln do_nothing
#endif // OI_DEBUG

#define MKPR make_pair
#define ALL(c) begin(c), end(c)
#define ALLn(arr, n) arr, arr+n
#define FILL0(arr) memset(arr, 0, sizeof(arr))
#define FILL1(arr) memset(arr, -1, sizeof(arr))

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;


constexpr ll MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
//Common variables

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) {
            return half * half * num;
        }
        else {
            return half * half;
        }
    }
}



int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;


    vector<ll> prefix(n+1);
    prefix[0] = 0;
    FOR (i, 1, n) {
        prefix[i] = prefix[i-1] + i;
    }
    ll advance = 0;

    vector<ll> modNum(20, (ll)1);
    int maxChanged = 2;
    for (;maxChanged <= n; maxChanged++) {
        modNum[maxChanged] = modNum[maxChanged-1] * (maxChanged);
        if (modNum[maxChanged] > 2e10)
            break;
    }
    // maxChanged--;

    // cout << "modNum:" << endl;
    // FOR(i, 1, maxChanged) {
    //     cout << modNum[i] << " ";
    // }
    // cout << endl;
    // cout << "maxChanged = " << maxChanged << endl;



    REP(i, q) {
        int kind;
        cin >> kind;
        if (kind == 1) {
            int l, r;
            cin >> l >> r;
            
            vector<ll> num(maxChanged);
            vector<bool> used(maxChanged, false);
            REP(i, maxChanged) {
                num[i] = n + 1 + i - maxChanged;
            }

            for (int j = maxChanged; j>=1; j--) {
                ll newOrder = (advance % modNum[j]) / modNum[j-1];
                int crtIndex = -1;

                REP(s, maxChanged) {
                    if (!used[s]) {
                        crtIndex++;
                        if (crtIndex == newOrder) {
                            used[s] = true;
                            // renew prefix

                            prefix[n+1-j] = prefix[n-j] + num[s];
                            break;
                        }
                    }
                }
            }

            cout << prefix[r] - prefix[l-1] << endl;


        }
        else {
            int x;
            cin >> x;
            advance += x;
        }

        // cout << "new permutation:" << endl;
        // FOR(i, 1, n) {
        //     cout << prefix[i] - prefix[i-1] << " ";
        // }
        // cout << endl;
    }
}