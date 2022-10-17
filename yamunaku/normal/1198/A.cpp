//
// Created by yamunaku on 2019/07/30.
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
    int n,s;
    cin >> n >> s;
    int k=8*s/n;
    if(k>=30){
        cout << 0 << endl;
        return 0;
    }
    k=(1<<k);
    vi a(n);
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    rep(i,n) mp[a[i]]++;
    if(mp.size()<k){
        cout << 0 << endl;
        return 0;
    }
    auto itr=mp.begin();
    int tmp=0;
    rep(i,k){
        tmp+=itr->second;
        itr++;
    }
    int ans=tmp;
    auto itr2=mp.begin();
    rep(i,mp.size()-k){
        tmp-=itr2->second;
        tmp+=itr->second;
        ans=max(ans,tmp);
        itr++;
        itr2++;
    }
    cout << n-ans << endl;
    return 0;
}