//
// Created by yamunaku on 2019/10/04.
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

struct sta{
    int x;
    int p;
};

struct gas{
    int p;
    int v;
};

int main(){
    int n, d, m;
    cin >> d >> n >> m;
    vector<sta> g(m);
    rep(i, m){
        cin >> g[i].x >> g[i].p;
    }
    sort(all(g), [](sta &l, sta &r){
        return l.x < r.x;
    });
    stack<gas> st;
    int sum = n;
    st.push({0, n});
    rep(i, m){
        if(sum < g[i].x){
            cout << -1 << endl;
            return 0;
        }
        while(st.top().p > g[i].p){
            if(sum - st.top().v < g[i].x){
                int r = st.top().v - (sum - g[i].x);
                sum -= st.top().v - r;
                st.top().v = r;
                break;
            }
            sum -= st.top().v;
            st.pop();
        }
        st.push({g[i].p, g[i].x + n - sum});
        sum = g[i].x + n;
    }
    if(sum < d){
        cout << -1 << endl;
        return 0;
    }
    while(sum > d){
        if(sum - st.top().v <= d){
            int r = st.top().v - (sum - d);
            sum -= st.top().v - r;
            st.top().v = r;
            break;
        }
        sum -= st.top().v;
        st.pop();
    }
    ll ans=0;
    while(!st.empty()){
        ans+=(ll)st.top().p*st.top().v;
        st.pop();
    }
    cout << ans << endl;
    return 0;
}