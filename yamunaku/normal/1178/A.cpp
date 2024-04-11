//
// Created by yamunaku on 2019/07/21.
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
    int n,m;
    cin >> n >> m;
    vector<int> a(n-1);
    rep(i,n-1) cin >> a[i];
    int c=1,total=m,my=m;
    vector<int> ans;
    rep(i,n-1){
        total+=a[i];
        if(2*a[i]<=m){
            c++;
            my+=a[i];
            ans.push_back(i+2);
        }
    }
    if(my*2>total){
        cout << c << endl;
        cout << 1;
        rep(i,c-1){
            cout << " " << ans[i];
        }
        cout << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}