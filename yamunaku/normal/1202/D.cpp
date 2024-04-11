//
// Created by yamunaku on 2019/08/14.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(ll i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(ll i = ((r)-1); i >= (l); i--)
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
    int t;
    cin >> t;
    rep(_,t){
        ll n;
        cin >> n;
        vector<pair<int,int>> p;
        perl(i,2,100001){
            ll k=i*(i-1)/2;
            if(n/k>0){
                p.push_back({i,n/k});
                n%=k;
            }
        }
        reverse(all(p));
        string ans="1";
        int pre=0;
        rep(i,p.size()){
            ans+=string(p[i].first-pre,'3')+string(p[i].second,'7');
            pre=p[i].first;
        }
        cout << ans << endl;
    }
    return 0;
}