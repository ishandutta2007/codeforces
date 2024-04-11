//
// Created by yamunaku on 2019/10/16.
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

struct point{
    int id;
    int x;
    int y;
    int z;
};

int main(){
    int n;
    cin >> n;
    int x, y, z;
    map<pair<int, int>, vector<point>> mp;
    rep(i, n){
        cin >> x >> y >> z;
        mp[{x, y}].push_back({i + 1, x, y, z});
    }
    map<int, vector<point>> mp2;
    for(auto &p:mp){
        vector<point> &v = p.second;
        sort(all(v), [](point &l, point &r){
            return l.z < r.z;
        });
        int i = 0;
        int sz = v.size();
        for(; i + 1 < sz; i += 2){
            x = v[i].id;
            y = v[i + 1].id;
            cout << x SP y << endl;
        }
        if(sz%2){
            mp2[v[sz-1].x].push_back(v[sz-1]);
        }
    }
    vector<point> mp3;
    for(auto &p:mp2){
        vector<point> &v = p.second;
        sort(all(v), [](point &l, point &r){
            return l.y < r.y;
        });
        int i = 0;
        int sz = v.size();
        for(; i + 1 < sz; i += 2){
            x = v[i].id;
            y = v[i + 1].id;
            cout << x SP y << endl;
        }
        if(sz%2){
            mp3.push_back(v[sz-1]);
        }
    }
    sort(all(mp3), [](point &l, point &r){
        return l.x < r.x;
    });
    int i = 0;
    int sz = mp3.size();
    for(; i + 1 < sz; i += 2){
        x = mp3[i].id;
        y = mp3[i + 1].id;
        cout << x SP y << endl;
    }
    return 0;
}