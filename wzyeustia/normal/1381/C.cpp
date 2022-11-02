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
        ll n, x, y; cin >> n >> x >> y;
        vector<ll> arr(n);
        vector<stack<ll>> places(n+2);

        REP(i, n) {
            cin >> arr[i];
            places[arr[i]].emplace(i);
        }

        priority_queue<pair<ll, ll>> pq;
        ll except;
        FOR(i, 1, n+1) {
            if (places[i].size() == 0) {
                except = i;
            }
            else {
                pq.emplace(places[i].size(), i);
            }
        }

        vector<ll> ans(n, 0);
        REP(i, x) {
            auto pa = pq.top(); pq.pop();
            ll idx = places[pa.second].top(); places[pa.second].pop();
            ans[idx] = pa.second;

            pq.emplace(places[pa.second].size(), pa.second);
        }

        y -= x;

        vector<ll> pos, val;
        if (!pq.empty()) {
            auto pa = pq.top(); pq.pop();
            // if (pa.first * 2 - n > y) {
            //     cout << "NO" << endl;
            //     continue; 
            // }

            REP(i, pa.first) {
                val.eb(pa.second);
            }

            while (!pq.empty()) {
                auto next = pq.top(); pq.pop();
                REP(i, next.first) {
                    pos.eb(places[next.second].top()); places[next.second].pop();
                    val.eb(next.second);
                }
            }

            REP(i, pa.first) {
                pos.eb(places[pa.second].top()); places[pa.second].pop();
            }
        }

        ll excount = n-x-y, id = 0;
        while (y > 0) {
            ans[pos[id]] = val[id];

            if (ans[pos[id]] == arr[pos[id]]) {
                if (excount > 0) {
                    excount--;
                    ans[pos[id]] = 0;
                }
                else {
                    break;
                }
            }
            else {
                y--;
            }
            id++;
        }

        if (y > 0) {
            cout << "NO" << endl;
            continue;
        }

        // ll lastCheck = 0;
        // REP(i, n) {
        //     if (ans[i] == arr[i]) {
        //         lastCheck++;
        //     }
        // }
        // if (lastCheck != x) {
        //     cout << "NO" << endl;
        //     continue;
        // }

        cout << "YES" << endl;
        REP(i, n) {
            if (ans[i] != 0) {
                cout << ans[i] << " "; 
            }
            else {
                cout << except << " ";
            }
        }ln;


    }
    return 0;
}