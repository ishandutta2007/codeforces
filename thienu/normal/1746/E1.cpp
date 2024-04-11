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

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void guess(int x){
    cout << "! " << x << endl;
    string s;
    cin >> s;
    if(s[1] == ')'){
        exit(0);
    }
}

bool query(vi s){
    cout << "? " << s.size();
    for(int i : s){
        cout << ' ' << i;
    }
    cout << endl;
    string a;
    cin >> a;
    return a == "YES";
}

vi intersection(vi s, vi t){
    vi res;
    int i = 0; int j = 0;
    while(i < s.size() || j < t.size()){
        // debug(s, t, i, j);
        if(i < s.size() && j < t.size() && s[i] == t[j]){
            res.push_back(s[i]);
            i++;
            j++;
        }
        else if(i != s.size() && (j == t.size() || s[i] < t[j])) i++;
        else j++;
    }
    return res;
}

// s - t
vi subtraction(vi s, vi t){
    vi res;
    int i = 0; int j = 0;
    while(i < s.size() || j < t.size()){
        // debug(s, t, i, j);
        if(i < s.size() && j < t.size() && s[i] == t[j]){
            i++;
            j++;
        }
        else if(i != s.size() && (j == t.size() || s[i] < t[j])){
            res.push_back(s[i]);
            i++;
        }
        else{
            j++;
        }
    }
    return res;
}

vi sunion(vi s, vi t){
    vi res;
    int i = 0; int j = 0;
    while(i < s.size() || j < t.size()){
        // debug(s, t, i, j);
        if(i < s.size() && j < t.size() && s[i] == t[j]){
            res.push_back(s[i]);
            i++;
            j++;
        }
        else if(i != s.size() && (j == t.size() || s[i] < t[j])){
            res.push_back(s[i]);
            i++;
        }
        else{
            res.push_back(t[j]);
            j++;
        }
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vi cand;
    for(int i = 1; i <= n; i++) cand.push_back(i);
    while(cand.size() > 2){
        int half = cand.size() / 2;
        int quarter = (cand.size() + 1) / 4;
        vi s1;
        vi s2;
        for(int i = 0; i < half; i++){
            s1.push_back(cand[i]);
            s2.push_back(cand[i + quarter]);
        }
        bool q1 = query(s1);
        bool q2 = query(s2);
        bool q3 = query(s2);
        bool q4 = query(s1);
        if(q2 == q3){
            if(q2){
                cand = s2;
            }else{
                cand = subtraction(cand, s2);
            }
        }
        else if(q1 == q4){
            if(q1){
                cand = s1;
            }else{
                cand = subtraction(cand, s1);
            }
        }
        else{
            if(!q1){
                s1 = subtraction(cand, s1);
            }
            if(!q3){
                s2 = subtraction(cand, s2);
            }
            debug(s1, s2, intersection(s1, s2), intersection(subtraction(cand, s1), subtraction(cand, s2)));
            cand = sunion(intersection(s1, s2), intersection(subtraction(cand, s1), subtraction(cand, s2)));
        }
        debug(cand);
    }
    for(int i : cand){
        guess(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}