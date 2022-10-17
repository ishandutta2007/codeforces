//
// Created by yamunaku on 2020/03/19.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

void manachar(string &s, vi &r){
    int i = 0, j = 0;
    r = vi(s.size());
    while(i < s.size()){
        while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) ++j;
        r[i] = j;
        int k = 1;
        while(i - k >= 0 && i + k < s.size() && k + r[i - k] < j) r[i + k] = r[i - k], ++k;
        i += k;
        j -= k;
    }
}

int main(){
    CFS;
    int q;
    cin >> q;
    rep(_, q){
        string s;
        cin >> s;
        int n = s.size();
        int h = 0;
        rep(i, n / 2){
            if(s[i] != s[n - i - 1]) break;
            h++;
        }
        int ans = 0;
        int id = -1;
        vi r;
        manachar(s, r);
        rep(i, n){
            r[i] = 2 * r[i] - 1;
        }
        rep(i, n){
            if(i - r[i] / 2 <= h || n - 1 - h <= i + r[i] / 2){
                int tmp = 2 * min(i - h, n - 1 - h - i) + 1;
                if(tmp > ans){
                    ans = tmp;
                    id = i;
                }
            }
        }
        string anss = s.substr(0, h) + s.substr(n - h, h);
        if(ans > 0) anss = s.substr(0, h) + s.substr(id - ans / 2, ans) + s.substr(n - h, h);

        ans = 0;
        id = -1;
        string t;
        rep(i, n){
            t.push_back(s[i]);
            t.push_back('#');
        }
        manachar(t, r);
        for(int idx = 1, i = 0; idx < 2 * n - 1; idx += 2, i++){
            int rt = ((2 * r[idx] - 1) / 2 + 1) / 2 * 2;
            if(i - rt / 2 + 1 <= h || n - 1 - h <= i + rt / 2){
                int tmp = max(ans, 2 * min(i - h, n - 1 - h - (i + 1)) + 2);
                if(tmp > ans){
                    ans = tmp;
                    id = i;
                }
            }
        }
        if(ans > 0){
            string anss2 = s.substr(0, h) + s.substr(id - ans / 2 + 1, ans) + s.substr(n - h, h);
            if(anss2.size() > anss.size()) anss = anss2;
        }
        cout << anss << endl;
    }
    return 0;
}