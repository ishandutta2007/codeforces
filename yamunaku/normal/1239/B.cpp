//
// Created by yamunaku on 2019/10/20.
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
    string s;
    cin >> n >> s;
    int l = 0, r = 0;
    rep(i, n){
        if(s[i] == '(') l++;
        else r++;
    }
    if(l != r){
        cout << 0 << endl << "1 1" << endl;
        return 0;
    }
    int ma = 0;
    int now = 0;
    rep(i, n){
        if(s[i] == ')') now++;
        else now--;
        if(now > ma){
            ma = now;
        }
    }
    struct aa{
        int type;
        int pos;
    };
    vector<aa> v;
    int count = 0;
    now = 0;
    rep(i, n){
        if(s[i] == ')') now++;
        else now--;
        if(now==ma) count++;
        else if(now == ma - 1){
            v.push_back({1, i});
        }else if(now == ma - 2){
            v.push_back({2, i});
        }
    }
    int ans = 0;
    int la = 0, ra = 0;
    int sz = v.size();
    rep(i, sz){
        v.push_back(v[i]);
    }
    int k = 0, lt = 0;
    rep(i, 2 * sz){
        if(v[i].type == 1){
            if(ans<k){
                ans=k;
                la=lt;
                ra=v[i].pos;
            }
            lt = -1;
            k = 0;
        }else{
            if(lt==-1) lt = v[i].pos;
            k++;
        }
    }
    ans+=count;

    now = 0;
    v = vector<aa>();
    rep(i, n){
        if(s[i] == ')') now++;
        else now--;
        if(now==ma){
            v.push_back({1, i});
        }else if(now == ma - 1){
            v.push_back({2, i});
        }
    }
    sz=v.size();
    rep(i, sz){
        v.push_back(v[i]);
    }
    k = 0, lt = 0;
    rep(i, 2 * sz){
        if(v[i].type == 1){
            if(ans<k){
                ans=k;
                la=lt;
                ra=v[i].pos;
            }
            lt = -1;
            k = 0;
        }else{
            if(lt==-1) lt = v[i].pos;
            k++;
        }
    }
    cout << ans << endl;
    cout << la + 1 SP ra + 1 << endl;
    return 0;
}