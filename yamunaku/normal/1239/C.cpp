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

struct SegmentTree{
private:
    int n;
    vector<pair<int, int>> node;

public:
    SegmentTree(int sz){
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2 * n - 1, {0, IINF});
        // for(int i=0; i<sz; i++) node[i+n-1] = {0,i;
        // for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1],node[2*i+2]);
    }

    void update(int x, ll val){
        x += (n - 1);
        node[x] = {val, x-(n-1)};
        if(val == 0) node[x].second = IINF;
        while(x > 0){
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    pair<int, int> getmin(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return {0, IINF};
        if(a <= l && r <= b) return node[k];
        pair<int, int> vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
        pair<int, int> vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};


int main(){
    CFS;
    int n;
    ll p;
    cin >> n >> p;
    vl t(n);
    rep(i, n) cin >> t[i];
    priority_queue<pair<ll, pair<int, int>>> event;
    rep(i, n) event.push({-t[i], {0, -i}});
    priority_queue<int> wait;
    queue<int> q;
    vl ans(n, -1);
    SegmentTree seg(n);
    while(!event.empty()){
        auto e = event.top();
        event.pop();
        if(e.second.first == 0){
            if(-e.second.second < seg.getmin(0, n).second){
                if(q.empty()){
                    event.push({e.first - p, {-1, -e.second.second}});
                }
                q.push(-e.second.second);
                seg.update(-e.second.second, -1);
            }else{
                wait.push(e.second.second);
            }
        }else{
            q.pop();
            ans[e.second.second] = -e.first;
            seg.update(e.second.second, 0);
            if(!wait.empty()){
                if(-wait.top() <= seg.getmin(0, n).second){
                    q.push(-wait.top());
                    seg.update(-wait.top(), -1);
                    wait.pop();
                }
            }
            if(!q.empty()){
                event.push({e.first - p, {-1, q.front()}});
            }
        }
    }
    rep(i, n){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}