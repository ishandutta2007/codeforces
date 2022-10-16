#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int A = 26;

bool same(int c, vi &cnt, int n, string &out){
    debug(cnt);
    if(cnt[c] > (n-2)/2) return false;
    int min_l = c;
    out += (char)('a'+min_l);
    out += (char)('a'+min_l);
    debug(out);
    debug(cnt);
    int last = min_l;
    for(int i = 0; i < n-2; i++){
        int left = n-2-i;
        bool can = last != min_l;
        bool forced = left + 1 <= cnt[min_l] * 2;
        debug(can, forced);
        if(forced){
            out += (char)('a'+min_l);
            cnt[min_l]--;
            last = min_l;
            continue;
        }
        for(int j = 0; j < A; j++){
            if((can || min_l != j) && cnt[j] > 0){
                out += (char)('a'+j);
                cnt[j]--;
                last = j;
                break;
            }
        }
    }
    return true;
}

bool diff(int a, int b, vi &cnt, int n, string &out){
    out += (char)('a'+a);
    out += (char)('a'+b);
    debug(out);

    int last = b;
    for(int i = 0; i < n-2; i++){
        int left = n-2-i;
        bool acan, aforced, bcan, bforced;
        if(cnt[a] + cnt[b] < left){
            acan = true;
            bcan = last != a;
            aforced = false;
            bforced = false;
        }else{
            if(last == a){
                aforced = true;
                bforced = false;
            }else{
                aforced = cnt[b] == 0;
                bforced = !aforced;
            }
        }
        if(aforced){
            out += (char)('a'+a);
            cnt[a]--;
            last = a;
            continue;
        }else if(bforced){
            out += (char)('a'+b);
            cnt[b]--;
            last = b;
            continue;
        }
        for(int j = 0; j < A; j++){
            if((acan || a != j) && (bcan || b != j) && cnt[j] > 0){
                out += (char)('a'+j);
                cnt[j]--;
                last = j;
                break;
            }
        }
    }

    // while(cnt[b] > 0){
    //     out += (char)('a'+b);
    //             cnt[b]--;
    // }
    // for(int i = 0; i < A; i++){
    //     if(i != a && i != b){
    //         while(cnt[i] > 0){
    //             out += (char)('a'+i);
    //             cnt[i]--;
    //         }
    //     }
    // }
    // while(cnt[a] > 0){
    //     out += (char)('a'+a);
    //             cnt[a]--;
    // }
    return true;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vi cnt(A);
    for(int i = 0; i < n; i++){
        cnt[s[i]-'a']++;
    }
    debug(cnt);
    int distinct = 0;
    int min_l = -1;
    int min_o = 1e9;
    int max_o = 1e9;
    for(int i = 0; i < A; i++){
        if(cnt[i] > 0){
            distinct++;
            if(cnt[i] < min_o){
                min_o = cnt[i];
                min_l = i;
            }
            max_o = max(max_o, cnt[i]);
        }
    }
    if(distinct == 1){
        cout << s << endl;
        return;
    }
    if(min_o == 1){
        string out = "";
        out += (char)('a'+min_l);
        cnt[min_l]--;
        for(int i = 0; i < A; i++){
            while(cnt[i] > 0){
                out += (char)('a'+i);
                cnt[i]--;
            }
        }
        cout << out << endl;
        return;
    }
    // if(max_o == 1){
    //     sort(s.begin(), s.end());
    //     cout << s << endl;
    //     return;
    // }
    debug("hard");

    string out;
    for(int a = 0; a < A; a++){
        for(int b = 0; b < A; b++){
            if(cnt[a] == 0 || cnt[b] == 0 || (a == b && cnt[a] == 1)) continue;
            out = "";
            vi x = cnt;
            x[a]--;
            x[b]--;
            bool ok;
            if(a == b) ok = same(a, x, n, out);
            else ok = diff(a, b, x, n, out);
            if(ok){
                cout << out << endl;
                return;
            }
        }
    }
    // debug(min_o, min_l);
    // string out = "";
    // out += (char)('a'+min_l);
    // out += (char)('a'+min_l);
    // debug(out);
    // cnt[min_l]-=2;
    // for(int i = 0; i < n-2; i++){
    //     if(i & 1){
    //         if(cnt[min_l] > 0){
    //             out += (char)('a'+min_l);
    //             cnt[min_l]--;
    //             continue;
    //         }
    //     }
    //     for(int j = 0; j < A; j++){
    //         if(cnt[j] > 0){
    //             out += (char)('a'+j);
    //             cnt[j]--;
    //             break;
    //         }
    //     }
    // }
    cout << out << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}