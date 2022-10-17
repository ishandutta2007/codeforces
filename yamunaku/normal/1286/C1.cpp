//
// Created by yamunaku on 2020/01/05.
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

string solve(int l, int r){
    cout << "? " << l + 1 << " " << r << endl;
    int len = r - l;
    int sz = len * (len + 1) / 2;
    vector<vector<string>> s(len + 1);
    rep(i, sz){
        string tmp;
        cin >> tmp;
        s[tmp.size()].push_back(tmp);
    }
    if(len==1){
        return s[1][0];
    }
    vi c(26, 0);
    string ans(len, '*');
    rep(i, len){
        c[s[len][0][i] - 'a']++;
    }
    repl(i, 2, len + 1){
        vi count(26, 0);
        rep(j, 26) count[j] += c[j] * i;
        rep(j, len){
            if(ans[j] != '*') count[ans[j] - 'a'] -= i - min(j + 1, len - j);
        }
        for(auto &t:s[i]){
            rep(j, i){
                count[t[j] - 'a']--;
            }
        }
        rep(j, 26){
            while(count[j] > 0){
                if(ans[i - 2] == '*') ans[i - 2] = j + 'a';
                else if(ans[len - (i - 2) - 1] == '*') ans[len - (i - 2) - 1] = j + 'a';
                count[j]--;
            }
        }
    }
    return ans;
}

int main(){
    // CFS;
    int n;
    cin >> n;
    if(n == 1){
        cout << "? 1 1" << endl;
        char c;
        cin >> c;
        cout << "! " << c << endl;
        return 0;
    }
    vector<string> v(2);
    v[0] = solve(0, n), v[1] = solve(0, n - 1);
//    cout << v[0] << endl << v[1] << endl;
    string ans(n, '*');
    char pre = '*';
    int s = (n - 1) / 2;
    int p = n % 2;
    ans[s] = v[1 - p][s];
    rep(i, n - 1){
//        cout << ans << endl;
        int sz = v[p].size();
        int nx = sz - s - 1;
//        cout << v[p][s] SP v[p][nx] <<endl;
        if(ans[s] == v[p][s]){
            ans[nx] = v[p][nx];
        }else{
            ans[nx] = v[p][s];
        }
        s = nx;
        p = 1 - p;
    }
    cout << "! " << ans << endl;
    return 0;
}