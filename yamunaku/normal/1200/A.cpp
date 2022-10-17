//
// Created by yamunaku on 2019/08/11.
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
    string s;
    cin >> s;
    vector<int> v(10,0);
    rep(i,n){
        if(s[i]=='L'){
            rep(j,10){
                if(v[j]==0){
                    v[j]=1;
                    break;
                }
            }
        }else if(s[i]=='R'){
            per(j,10){
                if(v[j]==0){
                    v[j]=1;
                    break;
                }
            }
        }else{
            v[s[i]-'0']=0;
        }
    }
    for(int i=0;i<10;i++){
        cout << v[i];
    }
    cout << endl;
    return 0;
}