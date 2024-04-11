//
// Created by yamunaku on 2019/08/22.
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
    int t;
    cin >> t;
    rep(_,t){
        int a,b,c;
        cin >> a >> b >> c;
        int x,y;
        cin >> x >> y;
        int ans=0;
        if(x>y){
            ans+=x*min(a/2,b);
            a-=2*min(a/2,b);
            ans+=y*min(a/2,c);
        }else{
            ans+=y*min(a/2,c);
            a-=2*min(a/2,c);
            ans+=x*min(a/2,b);
        }
        cout << ans << endl;
    }
    return 0;
}