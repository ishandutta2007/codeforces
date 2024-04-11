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

mti c;

inline void add(int l, int r, int d, int u){
    if(r<=l||u<=d) return;
    c[l][d]++;
    c[r][d]--;
    c[l][u]--;
    c[r][u]++;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<string> f(n);
    rep(i,n) cin >> f[i];
    c=mti(n+1,vi(n+1,0));
    rep(i,n){
        int l=100000, r=-1;
        rep(j,n){
            if(f[i][j]=='B'){
                l=min(l,j);
                r=max(r,j);
            }
        }
        if(r==-1){
            add(0,n,0,n);
        }else{
            add(max(0,r-k+1),l+1,max(0,i-k+1),i+1);
        }
    }
    rep(i,n){
        int l=100000, r=-1;
        rep(j,n){
            if(f[j][i]=='B'){
                l=min(l,j);
                r=max(r,j);
            }
        }
        if(r==-1){
            add(0,n,0,n);
        }else{
            add(max(0,i-k+1),i+1,max(0,r-k+1),l+1);
        }
    }
    rep(i,n){
        repl(j,1,n){
            c[i][j]+=c[i][j-1];
        }
    }
    rep(i,n){
        repl(j,1,n){
            c[j][i]+=c[j-1][i];
        }
    }
    int ma=0;
    rep(i,n){
        rep(j,n){
            ma=max(ma, c[i][j]);
        }
    }
    cout << ma << endl;
    return 0;
}