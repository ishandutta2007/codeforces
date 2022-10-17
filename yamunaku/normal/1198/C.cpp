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
    int q;
    cin >> q;
    rep(_,q){
        int n,m;
        cin >> n >> m;
        vi ok(3*n,1);
        vi anse;
        int u,v;
        rep(i,m){
            cin >> u >> v;
            u--,v--;
            if(ok[u]*ok[v]){
                anse.push_back(i+1);
                ok[u]=ok[v]=0;
            }
        }
        if(anse.size()>=n){
            cout << "Matching" << endl;
            rep(i,n){
                cout << anse[i] << " ";
            }
            cout << endl;
        }else{
            cout << "IndSet" << endl;
            int k=0;
            rep(i,3*n){
                if(ok[i]){
                    k++;
                    cout << i+1 << " ";
                }
                if(k==n) break;
            }
            cout << endl;
        }

    }
    return 0;
}