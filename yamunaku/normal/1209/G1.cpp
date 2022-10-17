//
// Created by yamunaku on 2019/09/14.
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
    int n,q;
    cin >> n >> q;
    if(q>0) return 0;
    vi a(n);
    rep(i,n){
        cin >> a[i];
    }
    map<int,int> l,r;
    rep(i,n){
        r[a[i]]=i;
    }
    per(i,n){
        l[a[i]]=i;
    }
    vi fl(n,0);
    for(auto &pp:l){
        fl[pp.second]|=1;
    }
    for(auto &pp:r){
        fl[pp.second]|=2;
    }
    map<int,int> count;
    set<int> st;
    int total=0;
    int ans=0;
    rep(i,n){
        total++;
        count[a[i]]++;
        if(fl[i]&1){
            st.insert(a[i]);
        }
        if(fl[i]&2){
            st.erase(a[i]);
        }
        if(st.size()==0){
            int ma=0;
            for(auto &pp:count){
                ma=max(ma,pp.second);
            }
            ans+=total-ma;
            total=0;
            count.clear();
        }
    }
    cout << ans << endl;
    return 0;
}