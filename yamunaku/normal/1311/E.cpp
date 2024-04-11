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
#define CYES cout<<"YES"<<endl
#define CNO cout<<"NO"<<endl
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
        int n, d;
        cin >> n >> d;
        if(n * (n - 1) / 2 < d){
            CNO;
            continue;
        }
        vi c(n + 1, 0);
        c[0] = 1;
        rep(i, n - 1){
            repl(j, 1, n + 1){
                if(c[j] < 2 * c[j - 1]){
                    c[j]++;
                    d -= j;
                    break;
                }
            }
        }
        if(d < 0){
            CNO;
            continue;
        }
        rep(i, d){
            repl(j, 1, n + 1){
                if(c[j] < 2 * (c[j - 1] - 1)){
                    c[j - 1]--;
                    c[j]++;
                    break;
                }
            }
        }
        CYES;
        int sum = 1;
        repl(i, 1, n + 1){
            if(c[i] == 0) break;
            rep(j, c[i]){
                cout << sum + j / 2 << " ";
            }
            sum += c[i - 1];
        }
        cout << endl;
    }
    return 0;
}