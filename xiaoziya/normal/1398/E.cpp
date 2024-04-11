//[]
#include <bits/stdc++.h>
using namespace std;
#define  enl          '\n'
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()

mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

void solve() {
    int n;
    cin>>n;

    int cnt = 0;
    int total_one = 0;
    set<pair<int,int>>dbl;
    set<int>s[2];

    int sm = 0;
    vector<int>sum = {0,0};

    for(int i=0;i<n;i++) {
        int tp,d;
        cin>>tp>>d;
        if(tp) total_one += (d>0 ? 1 : -1);
        if(tp and d>0) {
            s[1].insert(d);
            sum[1] += d;
        }
        else if(tp and d<0) {
            if(s[1].find(-d) != s[1].end()) {
                s[1].erase(s[1].find(-d));
                sum[1] += d;
            }
            else {
                cnt--;
                sm += d;
                dbl.erase(dbl.find({-d,1}));
            }
        }
        else if(d>0) {
            s[0].insert(d);
            sum[0] += d;
        }
        else {
            if(s[0].find(-d) != s[0].end()) {
                s[0].erase(s[0].find(-d));
                sum[0] += d;
            }
            else {
                sm += d;
                dbl.erase(dbl.find({-d,0}));
            }
        }

        while(sz(dbl) > total_one) {
            auto it = dbl.begin();
            sm -= (*it).first;
            if((*it).second) {
                cnt--;
                s[1].insert((*it).first);
                sum[1] += (*it).first;
            }
            else {
                s[0].insert((*it).first);
                sum[0] += (*it).first;
            }
            dbl.erase(it);
        }

        while(sz(dbl)<total_one) {
            cnt++;
            auto it = s[1].end();
            it--;
            sm += *it;
            sum[1] -= *it;
            dbl.insert({*it,1});
            s[1].erase(it);
        }

        if(dbl.empty()) {
            cout<<sum[0]<<enl;
            continue;
        }

        while(!s[0].empty() and *s[0].rbegin() > (*dbl.begin()).first) {
            auto it = dbl.begin();
            sm -= (*it).first;
            if((*it).second) {
                sum[1] += (*it).first;
                s[1].insert((*it).first);
                cnt--;
            }
            else {
                sum[0] += (*it).first;
                s[0].insert((*it).first);
            }
            dbl.erase(it);
            auto s_it = s[0].end();
            s_it--;
            sum[0] -= *s_it;
            sm += *s_it;
            dbl.insert({*s_it,0});
            s[0].erase(s_it);
        }

        while(!s[1].empty() and *s[1].rbegin() > (*dbl.begin()).first) {
            auto it = dbl.begin();
            sm -= (*it).first;
            if((*it).second) {
                cnt--;
                sum[1] += (*it).first;
                s[1].insert((*it).first);
            }
            else {
                s[0].insert((*it).first);
                sum[0] += (*it).first;
            }
            dbl.erase(it);
            auto s_it = s[1].end();
            s_it--;
            sum[1] -= *s_it;
            sm += *s_it;
            cnt++;
            dbl.insert({*s_it,1});
            s[1].erase(s_it);
        }

        int res = sum[0]+sum[1]+2*sm;

        if(total_one == cnt) {
            res -= (*dbl.begin()).first;
            if(!s[0].empty()) res += *s[0].rbegin();
        }

        cout<<res<<enl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);  
    int testcases = 1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}