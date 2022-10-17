//
// Created by yamunaku on 2019/08/14.
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
    map<char,pair<int,int>> mp={
            {'W',{0,1}},
            {'A',{1,0}},
            {'S',{0,-1}},
            {'D',{-1,0}}
    };
    rep(_,q){
        string s;
        cin >> s;
        ll nx=0,ny=0;
        ll l=0,r=0,u=0,d=0;
        rep(i,s.size()){
            nx+=mp[s[i]].first;
            ny+=mp[s[i]].second;
            l=min(l,nx);
            r=max(r,nx);
            u=max(u,ny);
            d=min(d,ny);
        }
        nx=0,ny=0;
        int a=-1,b=-1;
        int ca=0,cb=0;
        if(nx==l) a=0;
        else if(nx==r) a=1;
        if(ny==d) b=0;
        else if(ny==u) b=1;
        rep(i,s.size()){
            nx+=mp[s[i]].first;
            ny+=mp[s[i]].second;
            if(nx==l){
                if(a==1) ca++;
                a=0;
            }else if(nx==r){
                if(a==0) ca++;
                a=1;
            }
            if(ny==d){
                if(b==1) cb++;
                b=0;
            }else if(ny==u){
                if(b==0) cb++;
                b=1;
            }
        }
        if(r<=l+1) ca=100;
        if(u<=d+1) cb=100;
        ll ans=(r-l+1)*(u-d+1);
        if(ca<=1){
            ans=min(ans,(r-l)*(u-d+1));
        }
        if(cb<=1){
            ans=min(ans,(r-l+1)*(u-d));
        }
        cout << ans << endl;
    }
    return 0;
}