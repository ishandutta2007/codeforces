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
    int n;
    cin >> n;
    int m;
    repl(i,n,n*3/2){
        bool ok=true;
        repl(j,2,sqrt(i)+10){
            if(i%j==0&&i/j!=1){
                ok=false;
                break;
            }
        }
        if(ok){
            m=i;
            break;
        }
    }
    cout << m << endl;
    rep(i,n){
        cout << i+1 SP (i+1)%n+1 << endl;
    }
    int k=n/2;
    rep(i,m-n){
        cout << i+1 SP i+1+k << endl;
    }
    return 0;
}