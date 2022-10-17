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

int main(){
    int q;
    cin >> q;
    rep(_,q){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ok;
        rep(i,10){
            vi us(n,0);
            int now=i;
            per(j,n){
                if(us[j]==0&&s[j]-'0'<=now){
                    now=s[j]-'0';
                    us[j]=1;
                }
            }
            now=i;
            rep(j,n){
                if(us[j]==0&&s[j]-'0'>=now){
                    now=s[j]-'0';
                    us[j]=2;
                }
            }
            ok=true;
            rep(j,n){
                if(us[j]==0){
                    ok=false;
                    break;
                }
            }
            if(ok){
                rep(j,n){
                    cout << us[j];
                }
                cout << endl;
                break;
            }
        }
        if(!ok) cout << "-" << endl;
    }
    return 0;
}