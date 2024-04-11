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
typedef long double ld;


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
    if (a < b) swap(a, b);
    return (a % b == 0)? b: gcd(b, a%b);
}


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 1e9+7;

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        string str; cin >> str;
        
        vector<ll> leftLower(n+1, 0), leftUpper(n+1, 0), rightLower(n+2, 0), rightUpper(n+2, 0);
        vector<ll> pos(n+1, 0);
        ll lPos = 0;
        for(int i = 1; i <= n; i++) {
            if (str[i-1] == '+')
                lPos++;
            else lPos--;

            pos[i] = lPos;
            leftLower[i] = min(lPos, leftLower[i-1]);
            leftUpper[i] = max(lPos, leftUpper[i-1]);
        }

        rightLower[n] = rightUpper[n] = pos[n];
        ll rPos = pos[n];
        for (int i = n-1; i >= 0; i--) {
            if (str[i] == '+') {
                rPos--;
            } else rPos++;

            rightLower[i] = min(rPos, rightLower[i+1]);
            rightUpper[i] = max(rPos, rightUpper[i+1]);
        }
        // REP(i, n+1) {
        //     cout << leftLower[i] << "\t";
        // }ln;
        // REP(i, n+1) {
        //     cout << leftUpper[i] << "\t";
        // }ln;
        // REP(i, n+1) {
        //     cout << rightLower[i] << "\t";
        // }ln;
        // REP(i, n+1) {
        //     cout << rightUpper[i] << "\t";
        // }ln;ln;
        
        REP(i, m) {
            ll l, r; cin >> l >> r;
            ll low = leftLower[l-1], upp = leftUpper[l-1], cur = pos[l-1];
            chkmin(low, cur + rightLower[r] - pos[r]);
            chkmax(upp, cur + rightUpper[r] - pos[r]);

            // cout << "paras: " << low << " " << upp << endl;
            cout << upp - low + 1 << endl;
        }
        
    }
    return 0;
}