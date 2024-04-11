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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    get(n);get(k);

    vector<int> arr(n+2);
    FOR (i, 1, n) {
        cin >> arr[i];
        arr[i] += n+3-i;
    }
    arr[0] = 1;
    arr[n+1] = 0x7f7f7f7f;

    // showArr("arr:", arr, n+2);

    vector<bool> fixed(n+2, false);
    vector<int> checkSequence;
    checkSequence.eb(0);
    checkSequence.eb(n+1);
    REP(i, k) {
        int temp;
        cin >> temp;
        checkSequence.eb(temp);
        fixed[temp] = true;
    }
    fixed[0] = true;
    fixed[n+1] = true;

    sort(checkSequence.begin(), checkSequence.end());

    bool success = true;
    vector<int> length(n+2, 0);
    int ans = 0;

    REP(i, k+1) {
        int startIndex = checkSequence[i], endIndex = checkSequence[i+1];
        if (arr[endIndex] < arr[startIndex]) {
            success = false;
            break;
        }

        // cout << "start: " << startIndex << " end: " << endIndex << endl; 

        set<pair<int, int>> newSet;
        // newSet.emplace(0, 0);
        length[startIndex] = 1;
        newSet.emplace(arr[startIndex], length[startIndex]);

        unordered_map<int, int> fromLengthToMaxVal;
        fromLengthToMaxVal[length[startIndex]] = arr[startIndex];
        
        FOR (j, startIndex+1, endIndex) {
            // cout << "--------------------" << endl;
            // cout << "checking " << j << endl;
            // cout <<"searching: " << arr[j]+1 << " " << 0 << endl;
            set<pair<int, int>>::iterator lower = newSet.lower_bound(make_pair(arr[j]+1, 0));
            if (lower == newSet.begin()) {
                // cout << j << " continue" << endl;
                continue;
            }
            lower--;

            // cout << "lower:" << lower->first << " " << lower->second << endl;


            
            // if (arr[j] - arr[startIndex] < j - startIndex)
            //     continue;

            length[j] = lower->second +1;
            newSet.emplace(arr[j], length[j]);
            // cout << "length: " << length[j] << endl;

            if(fromLengthToMaxVal[length[j]] == 0 || fromLengthToMaxVal[length[j]] > arr[j]) {
                pair<int, int> erased = make_pair(fromLengthToMaxVal[length[j]], length[j]);
                // cout << "erase " << erased.first << " " << erased.second << endl;
                newSet.erase(erased);
                fromLengthToMaxVal[length[j]] = arr[j];
            }

            // cout << "set: " << endl;
            // for(auto& p : newSet) {
            //     cout << p.first << " " << p.second << " | ";
            // }
            // ln;
        }
        
        ans += (endIndex - startIndex + 1) - length[endIndex];

        // cout << "ans: " << ans << endl;
    }

    if (success) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
    //Main program
}