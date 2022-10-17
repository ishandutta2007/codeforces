//
// Created by yamunaku on 2019/10/07.
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
    CFS;
    int q;
    cin >> q;
    rep(_, q){
        int n;
        cin >> n;
        vi a(n);
        rep(i, n) cin >> a[i], a[i]--;
        vi l(n, -1), r(n, -1);
        rep(i, n){
            if(l[a[i]] == -1) l[a[i]] = i;
            r[a[i]] = i;
        }
        int sz = 0;
        rep(i, n){
            if(l[i] != -1){
                l[sz] = l[i];
                r[sz] = r[i];
                sz++;
            }
        }
        int rb = 1;
        int ans = 0;
        rep(i, sz){
            if(i == rb) rb++;
            while(rb < sz){
                if(r[rb-1]>l[rb]) break;
                rb++;
            }
            ans = max(ans, rb - i);
        }
        cout << sz - ans << endl;
    }
    return 0;
}