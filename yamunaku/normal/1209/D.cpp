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

class UnionFind{
    vi node;
public:
    UnionFind(int sz){
        node=vi(sz);
        iota(all(node),0);
    }
    int root(int x){
        if(x==node[x])return x;
        return node[x]=root(node[x]);
    }
    bool uni(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y) return false;
        node[x]=y;
        return true;
    }
};

int main(){
    int n,k;
    cin >> n >> k;
    UnionFind uf(n);
    int ans=0;
    rep(i,k){
        int a,b;
        cin >> a >> b;
        if(!uf.uni(a-1,b-1)) ans++;
    }
    cout << ans << endl;
    return 0;
}