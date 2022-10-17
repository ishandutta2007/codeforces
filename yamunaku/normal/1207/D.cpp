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

vector<ll> fact;

void buildFact(int n){
    fact = vector<ll>(n + 1, 1);
    for(int i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * i % MOD9;
    }
}


int main(){
    CFS;
    int n;
    cin >> n;
    buildFact(n);
    vector<pair<int, int>> p(n);
    rep(i, n){
        cin >> p[i].first >> p[i].second;
    }
    ll count=1;
    ll a=1,b=1,k=1;
    sort(all(p));
    rep(i, n - 1){
        if(p[i].second>p[i+1].second){
            k=0;
        }
        if(p[i].first==p[i+1].first){
            count++;
        }else{
            a=a*fact[count]%MOD9;
            count=1;
        }
    }
    a=a*fact[count]%MOD9;
    count=1;
    rep(i, n - 1){
        if(p[i]==p[i+1]){
            count++;
        }else{
            k=k*fact[count]%MOD9;
            count=1;
        }
    }
    k=k*fact[count]%MOD9;
    count=1;
    sort(all(p),[](pair<int,int> &l, pair<int,int> &r){
        return l.second==r.second?l.first<r.first:l.second<r.second;
    });
    rep(i, n - 1){
        if(p[i].second==p[i+1].second){
            count++;
        }else{
            b=b*fact[count]%MOD9;
            count=1;
        }
    }
    b=b*fact[count]%MOD9;
    cout << ((fact[n]-a-b+k)%MOD9+MOD9)%MOD9 << endl;
    return 0;
}