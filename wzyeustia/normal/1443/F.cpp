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

    int t;
    cin >> t;
    REP(I, t){
        int n, k;
        cin >> n >> k;

        vector<int> a(n+1), b, pos(n+1, -1), seq(n+1, 0);

        REP(i, n) {
            cin >> a[i];
            pos[a[i]] = i;
        }

        int temp;
        REP(i, k) {
            cin >> temp;
            b.eb(temp);
            seq[pos[temp]] = i+1;
        }

        // REP(i, n) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // REP(i, n) {
        //     cout << seq[i] << " ";
        // }
        // cout << endl;

        int currentCount = 0;
        vector<int> counts, forSim, getSeq(k + 1);

        REP(i, n) {
            if (seq[i] == 0) {
                currentCount++;
            }
            else {
                counts.eb(currentCount);
                currentCount = 0;
                forSim.eb(seq[i]);
                getSeq[seq[i]] = counts.size();
            }
        }
        counts.eb(currentCount);


        // cout << "counts:" << endl;
        // REP(i, k+1) {
        //     cout << counts[i] << " ";
        // }
        // cout << endl;
        // cout << "seq:" << endl;
        // REP(i, n) {
        //     cout << seq[i] << " ";
        // }
        // cout << endl;
        // cout << "getSeq:" << endl;
        // FOR(i, 1, k) {
        //     cout << getSeq[i] << " ";
        // }
        // cout << endl;

        ll ans = 1;
        FOR(i, 1, k) {
            int idx = getSeq[i];
            int valid = 0;
            if (counts[idx - 1] > 0)
                valid++;
            if (counts[idx] > 0)
                valid++;

            // cout << "idx = " << idx << endl;
            // cout << "valid = " << valid << endl;

            ans = (ans * valid) % 998244353;
            counts[idx-1] = max(counts[idx], counts[idx-1]);
            counts[idx] = max(counts[idx], counts[idx-1]);
        }

        cout << ans << endl;
    }
}