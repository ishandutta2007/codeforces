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
 
ll getReverse(ll y, ll modNum) {
    return fastPow(y, modNum - 2, modNum) % modNum;
}
 
ll gcd(ll a, ll b) {
    return (a % b == 0)? b: gcd(b, a%b);
}

void dfs(vector<ll> &seq, vector<vector<ll>> child, int i) {
    for (auto& adj : child[i]) {
        dfs(seq, child, adj);
    }
    seq.emplace_back(i);
}

// struct info : pair<int, int>{
//     int constraint;
//     int number = 0;
// };
typedef pair<int, int> info;
#define constraint first
#define number second

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    get(n);
    vector<info> infos;
    vector<int> positions;
    vector<int> answer(n);
    int cPosition = 0;
    infos.eb(0, 0);

    bool success = true;
    REP(i, 2 * n) {
        char ch;
        cin >> ch;
        if (ch == '+') {
            infos[infos.size()-1].number++;
            positions.eb(cPosition++);
        }
        else {
            get(remove);
            vector<info>::iterator cut = lower_bound(infos.begin(), infos.end(), make_pair(remove, 0), greater<pii>());
            vector<info>::iterator temp = cut;
            // if (cut->constraint == 0 && cut->number == 0) {
            //     success = false;
            //     continue;
            // }

            // cout << "lower bound: " << cut->first << " " << cut->second << endl;


            int restSlot = 0;
            for (; temp != infos.end(); temp++) {
                restSlot += temp->number;
            }
            infos.resize(cut - infos.begin());

            // cout << "restSlot:" << restSlot << endl;
            if (restSlot == 0) {
                success = false;
            }
            else {
                answer[positions.back()] = remove;
                positions.pop_back();
                

                infos.eb(remove, restSlot-1);
                infos.eb(0, 0);
            }

            
        }

        // cout << "infos:" << endl;
        // for (auto& info : infos) {
        //     cout << info.first << " " << info.second << " | ";
        // }
        // ln;
    }

    if (success) {
        cout << "YES" << endl;
        REP(i, n) {
            cout << answer[i] << " ";
        }
        ln;
    }
    else {
        cout << "NO" << endl;
    }
}