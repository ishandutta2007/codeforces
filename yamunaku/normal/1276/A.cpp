//
// Created by yamunaku on 2019/12/14.
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
    int q;
    cin >> q;
    rep(_,q){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> ans(n,false);
        rep(i,n-2){
            if(s.substr(i, 3)=="one") ans[i+1]=true;
            if(s.substr(i, 3)=="two") ans[i+1]=true;
        }
        rep(i,n-4){
            if(s.substr(i,5)=="twone"){
                ans[i+2]=true;
                ans[i+1]=ans[i+3]=false;
            }
        }
        int count = 0;
        rep(i,n) if(ans[i]) count++;
        cout << count << endl;
        rep(i,n) if(ans[i]) cout << i+1 << " ";
        cout << endl;
    }
    return 0;
}