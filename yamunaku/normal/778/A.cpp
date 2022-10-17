//
// Created by yamunaku on 2019/10/11.
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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vi a(n);
    rep(i, n) cin >> a[i];
    int l = 0, r = n+1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        vi flag(n, true);
        rep(i, mid){
            flag[a[i]-1] = false;
        }
        int idx = 0;
        bool ok = false;
        rep(i, n){
            if(s[i] == t[idx] && flag[i]) idx++;
            if(idx == m){
                ok = true;
                break;
            }
        }
        if(ok){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}