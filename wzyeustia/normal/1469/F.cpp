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
#define chkmax(a, b) a = max((long long) a, (long long) b)

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

#define ln cout << endl;
#define show(str, x) cout << str << x; ln
#define showArr(str, arr, size) cout << str; ln; REP(test, size) {cout << arr[test] << " ";} ln

#define get(x) int x; cin >> x
#define getArr(arr, n) REP(i, n) {cin >> arr[i];}

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;


constexpr ll MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
//Common variables

ll fastPow(ll num, ll exp, ll modNum) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2, modNum) % modNum;
        if (exp % 2 == 1) {
            return (((half * half) % modNum) * num) % modNum;
        }
        else {
            return (half * half) % modNum;
        }
    }
}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) {
            return (((half * half)) * num);
        }
        else {
            return (half * half);
        }
    }
}
 
ll getReverse(ll y, ll modNum) {
    return fastPow(y, modNum - 2, modNum) % modNum;
}
 
ll gcd(ll a, ll b) {
    return (a % b == 0)? b: gcd(b, a%b);
}

ll lowbit(ll n) {return n & -n;}

void add(vector<ll> &BIT, ll val, int lo, int hi) {
    for (int i = lo; i < BIT.size(); i+=lowbit(i)) {
        BIT[i]+=val;
    }
    for (int i = hi+1; i < BIT.size(); i+=lowbit(i)) {
        BIT[i]-=val;
    }
}

ll check(vector<ll> &BIT, int pos) {
    ll ret = 0;
    for (int i = pos; i > 0; i-=lowbit(i)) {
        ret += BIT[i];
    }
    return ret;
}

void update(vector<ll> &BIT, ll len, ll lowest, ll &depth) {
    // cout << "add chain len " << len << " at " << lowest << endl; 
    ll lo = lowest+2;
    add(BIT, 1, lo, lo+(len-2)/2);
    add(BIT, 1, lo, lo+(len-3)/2);
    add(BIT, -1, lowest, lowest);
    chkmax(depth, lo+(len-2)/2);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, k; cin >> n >> k;
        vector<ll> len(n);
        REP(i, n) {cin >> len[i];}
        sort(all(len), greater<int>());

        const ll SIZE = 1e7+7;
        vector<ll> BIT(SIZE);

        add(BIT, 1, 1, 1);
        ll idx = 0, lowest = 1, depth = 1;
        while (check(BIT, lowest) + check(BIT, lowest+1) < k) {
            int cnt = check(BIT, lowest);
            while (cnt > 0) {
                update(BIT, len[idx++], lowest, depth);
                cnt--;
                if (idx == n) break;

            }
            if (cnt == 0) lowest++;
            if (idx == n) break;
        }

        // cout << "BIT: ";
        // REP(i, 10) {
        //     cout << check(BIT, i) << " ";
        // }ln;
        // cout << "lowest: " << lowest << endl; 

        ll sum = 0;
        while (true) {
            int crt = check(BIT, lowest);
            sum += crt;
            if (sum >= k || lowest == depth) break;
            lowest++;
        }

        if (sum >= k) {
            cout << lowest-1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}