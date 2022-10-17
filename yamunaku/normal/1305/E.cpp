//
// Created by yamunaku on 2020/03/03.
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
    int n, m;
    cin >> n >> m;
    ll total = 0;
    perl(i, 1, n + 1){
        total += (i - 1) / 2;
    }
    if(m > total){
        cout << -1 << endl;
        return 0;
    }
    total -= m;
    if(total == 0){
        repl(i, 1, n + 1){
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }
    perl(i, 1, n + 1){
        if(total <= (i - 1) / 2){
            repl(j, 1, i){
                cout << j << " ";
            }
            cout << 2 * total + i << " ";
            repl(j, i + 1, n + 1){
                cout << IINF - (n - j) * 10000 << " ";
            }
            cout << endl;
            return 0;
        }
        total -= (i - 1) / 2;
    }
    return 0;
}