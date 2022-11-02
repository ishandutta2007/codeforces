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

void dfs(vector<ll> &seq, vector<vector<ll>> child, int i) {
    for (auto& adj : child[i]) {
        dfs(seq, child, adj);
    }
    seq.emplace_back(i);
}

int lowbit(int x)
{
    return x&(-x);
}

void edit(vector<int> &BIT, int k, int n) {
    // cout << "editing..." << endl;
    // cout << "k = " << k << endl;
    if (k == 0) return;

    for (int i = k; i <= n; i += lowbit(i)) {
        BIT[i]++;
    }
}

int check(vector<int> &BIT, int k) {
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i)) {
        ans += BIT[i];
    }
    return ans;
}

int countDivisor(int n, int k) {
    int count = 0;
    while (n % k == 0) {
        count++;
        n /= k;
    }
    return count;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const int UPPER = trunc(sqrt(1e9)) + 5;
    vector<bool> isPrime(UPPER+1, true);
    isPrime[0] = isPrime[1] = false;

    vector<int> primes;
    for (int i = 2; i < UPPER + 1; i++) {
        if (isPrime[i]) {
            primes.eb(i);
        }
        for (auto& prime : primes) {
            if (i * prime > UPPER)
                break;
            
            isPrime[i*prime] = false;
            if (i % prime == 0)
                break;
        }
    }

    // showArr("primes:", primes, primes.size());


    get(t);
    REP(I, t) {
        get(n);

        vector<int> divisor;
        vector<vector<int>> numDivisor;
        int temp = n;

        for (int i = 0; i < primes.size(); i++) {
            if (temp % primes[i] == 0) {
                int count = 0;
                int div = 1;
                vector<int> divs;

                while (temp % primes[i] == 0) {
                    count++;
                    div *= primes[i];
                    divs.eb(div);
                    temp /= primes[i];
                }

                divisor.eb(primes[i]);
                numDivisor.eb(divs);
            }
        }

        if (temp != 1) {
            divisor.eb(temp);
            numDivisor.eb(vector<int>(1, temp));
        }

        // for (auto& div : divisor) {
        //     cout << div << " ";
        // }ln;
        // for (auto& num : numDivisor) {
        //     cout << num << " ";
        // }ln;

        if (divisor.size() == 1) {
            for (auto& div : numDivisor[0]) {
                cout << div << " ";
            }ln;
            cout << 0 << endl;
        }

        if (divisor.size() == 2) {
            for (auto& div : numDivisor[0]) {
                cout << div << " ";
            }

            for (auto& div0 : numDivisor[0]) {
                for (auto& div1 : numDivisor[1]) {
                    if (div0 * div1 != divisor[0] * divisor[1])
                        cout << div0 * div1 << " ";
                }
            }

            for (auto& div : numDivisor[1]) {
                cout << div << " ";
            }

            cout << divisor[0] * divisor[1] << endl;

            if (numDivisor[0].size() == 1 && numDivisor[1].size() == 1) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }

        vector<int> output0, output1;

        int pp = divisor.size();
        if (divisor.size() >= 3) {
            unordered_set<int> set;
            for (int i = 0; i < pp; i++) {
                set.emplace(divisor[i] * divisor[(i+1)%pp]);
            };

            for (int i = 0; i < pp; i++) {
                // output1 = vector<int>(output0);

                int thisEnd = output0.size();
                for (int s = 0; s < thisEnd; s++) {
                    int div = output0[s];
                    for (auto& mul : numDivisor[i]) {
                        int out = div * mul;
                        if (set.count(out) == 0)
                            cout << out << " ";
                        output0.eb(out);
                    }
                }

                for (auto& div : numDivisor[i]) {
                    cout << div << " ";
                    output0.eb(div);
                }
                cout << divisor[i] * divisor[(i+1)%pp] << " ";

                // output0 = output1;
            }ln;

            cout << 0 << endl;
        }

    }
    
}