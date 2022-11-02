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

void add(vector<int> &BIT, int lo, int hi) {
    for (int i = lo; i < BIT.size(); i+=lowbit(i)) {
        BIT[i]++;
    }
    for (int i = hi+1; i < BIT.size(); i+=lowbit(i)) {
        BIT[i]--;
    }
}

ll check(vector<int> &BIT, int pos) {
    ll ret = 0;
    for (int i = pos; i > 0; i-=lowbit(i)) {
        ret += BIT[i];
    }
    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        vector<int> BIT(n+1);

        const int NUM = 21;
        
        if (k > NUM) {
            REP(i, n) {
                if (str[i] == '0') {
                    add(BIT, max(1, i-k+NUM), i+1);
                }
            }
        }

        vector<bool> invalid(4e6, false);
        REP(i, n-k+1) {
            if (check(BIT, i+1) == 0) {
                // cout << "checking " << i << endl;
                ll num = 0, mul = 1;

                int limit = max(0, max(i+k-NUM, i));
                for (int j = i+k-1; j >= limit; j--) {
                    if (str[j] == '0') {
                        num += mul;
                    }
                    mul *= 2;
                }
                // cout << "find " << num << endl;

                invalid[num] = true;
            }
        }

        int pos = 0;
        while (invalid[pos]) pos++;
        if (k <= NUM && pos >= fastPow(2, k)) {
            cout << "NO" << endl;
            continue;
        }


        cout << "YES" << endl;
        if (k > NUM) {
            for (int i = k; i > NUM; i--) {
                cout << "0";
            }
        }
        int div = fastPow(2, min(NUM-1, k-1));
        for (int i = div; i > 0; i/=2) {
            if (pos / i) {
                cout << "1";
                pos -= i;
            }
            else {
                cout << "0";
            }
        }ln;
    }
    return 0;
}