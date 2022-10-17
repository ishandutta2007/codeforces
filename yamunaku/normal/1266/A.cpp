//
// Created by yamunaku on 2019/12/18.
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

int main(){
    // CFS;
    int q;
    cin >> q;
    rep(t, q){
        string s;
        cin >> s;
        int n = s.size();
        int sum = 0;
        bool ok = false, ok2 = false;
        rep(i, n){
            sum += s[i] - '0';
            if((s[i] - '0') % 2 == 0){
                if(s[i] == '0'){
                    if(ok) ok2 = true;
                }else{
                    ok2 = true;
                }
            }
            if(s[i] == '0') ok = true;
        }
        if(sum % 3 == 0 && ok && ok2) cout << "red" << endl;
        else cout << "cyan" << endl;
    }
    return 0;
}