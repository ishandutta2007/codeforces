#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 40;
const int MAXK = 10;

int n, k;
LL active[MAXK+1];
LL bb[MAXK];
LL pref[MAXK][MAXN+1];
LL q[MAXK];
int inactive[MAXK];

bool recur(LL S, int it) {
    if (it == k-1) {
        int ones = __builtin_popcountll(S);
        int zeros = n-ones;
        LL sortedS = ((1ll<<ones)-1)<<zeros;
        LL diff = S ^ sortedS;
        return (diff & bb[it]) == diff;
    }
    int min_ones = __builtin_popcountll(S & bb[it]);
    S |= bb[it];
    for (int ones = min_ones; ones <= min_ones + inactive[it]; ones++) {
        if (recur(S & pref[it][ones], it+1) == false) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    
    cin >> n;

    if (n == 1) {
        cout << "ACCEPTED\n";
        return 0;
    }
    
    cin >> k;
    for (int it = 0; it < k; it++) {
        cin >> q[it];
        pref[it][q[it]] = (1ll<<n)-1;
        for (int i = 0; i < q[it]; i++) {
            int x;
            cin >> x;
            x--;
            bb[it] |= 1ll<<x;
            pref[it][q[it]-(i+1)] = ~bb[it];
        }
        inactive[it] = __builtin_popcountll(bb[it]&(~active[it]));
        active[it+1] = active[it] | bb[it];
    }

    if (q[k-1] == n) {
        cout << "ACCEPTED\n";
        return 0;
    }

    if (active[k-1] != (1ll<<n)-1) {
        cout << "REJECTED\n";
        return 0;
    }

    if (!recur(0, 0)) cout << "REJECTED\n";
    else cout << "ACCEPTED\n";
}