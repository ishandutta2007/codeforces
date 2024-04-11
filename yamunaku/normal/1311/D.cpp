//
// Created by yamunaku on 2020/02/24.
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
    CFS;
    int t;
    cin >> t;
    rep(_, t){
        int a, b, c;
        cin >> a >> b >> c;
        vi dp(20001, IINF);
        vi mi(20001, -1);
        repl(i, 1, 20001){
            for(int j = i; j <= 20000; j += i){
                if(abs(a - i) < dp[j]){
                    dp[j] = abs(a - i);
                    mi[j] = i;
                }
            }
        }
        int ans = IINF;
        int x, y, z;
        repl(i, 1, 20001){
            int tmp = c / i;
            int v = dp[i] + abs(b - i) + min(abs(tmp * i - c), abs((tmp + 1) * i - c));
            if(v < ans){
                ans = v;
                x = mi[i];
                y = i;
                z = (abs(tmp * i - c) < abs((tmp + 1) * i - c) ? tmp * i : (tmp + 1) * i);
            }
        }
        cout << ans << endl;
        cout << x SP y SP z << endl;
    }
    return 0;
}