//
// Created by yamunaku on 2019/08/25.
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
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    int ans=IINF;
    rep(i,n){
        map<int,int> mp;
        rep(j,n){
            mp[a[j]]++;
        }
        int c=0;
        for(auto p:mp){
            if(p.second>1) c++;
        }
        if(c==0){
            cout << 0 << endl;
            return 0;
        }
        int j=i;
        for(;j<n;j++){
            mp[a[j]]--;
            if(mp[a[j]]==1){
                c--;
                if(c==0) break;
            }
        }
        if(c==0) ans=min(ans,j-i+1);
    }
    cout << ans << endl;
    return 0;
}