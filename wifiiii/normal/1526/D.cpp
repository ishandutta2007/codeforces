#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct BIT {
    vector<T> a;
    int n;
    BIT() {}
    BIT(int _n) {n=_n+1;a.resize(n+1);}
    void init(int _n) {n=_n+1;a.resize(n+1);}
    void add(int x,T v){++x;for(;x<=n;x+=x&-x)a[x]+=v;}
    T sum(int x) {++x;T ret=0;for(;x;x-=x&-x)ret+=a[x];return ret;}
};
string turn(string s) {
    for(char &c : s) {
        if(c == 'A') c = '0';
        if(c == 'N') c = '1';
        if(c == 'O') c = '2';
        if(c == 'T') c = '3';
    }
    return s;
}
ll dis(const string &s, const string &t) {
    int n = s.size();
    vector<vector<int>> pos1(4);
    vector<vector<int>> pos2(4);
    for(int i = 0; i < n; ++i) {
        pos1[s[i] - '0'].push_back(i);
    }
    for(int i = 0; i < n; ++i) {
        pos2[t[i] - '0'].push_back(i);
    }
    vector<int> match(n);
    for(int i = 0; i < 4; ++i) {
        if(pos1[i].empty()) continue;
        assert(pos1[i].size() == pos2[i].size());
        for(int j = 0; j < pos1[i].size(); ++j) {
            match[pos1[i][j]] = pos2[i][j];
        }
    }
    BIT<int> bit(n);
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += i - bit.sum(match[i]);
        bit.add(match[i], 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
//    clock_t be = clock();
    while(t--) {
        string s;
        cin >> s;
        s = turn(s);
        vector<int> cnt(4);
        for(char c : s) cnt[c-'0'] += 1;
        vector<int> ord;
        for(int i = 0; i < 4; ++i) {
            if(cnt[i]) ord.push_back(i);
        }
        ll mx = -1; string ans;
        do {
            string x;
            for(int i : ord) x += string(cnt[i], '0'+i);
            ll d = dis(s, x);
            if(d > mx) {
                mx = d;
                ans = x;
            }
        } while(next_permutation(ord.begin(), ord.end()));
        for(char &c : ans) {
            if(c == '0') c = 'A';
            if(c == '1') c = 'N';
            if(c == '2') c = 'O';
            if(c == '3') c = 'T';
        }
        cout << ans << '\n';
    }
//    cout << (double)(clock() - be) / CLOCKS_PER_SEC << '\n';
}