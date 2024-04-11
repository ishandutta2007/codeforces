//
// Created by yamunaku on 2019/10/11.
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

void parse(vector<string> &s, string &t){
    s.push_back("");
    int sz = t.size();
    rep(i, sz){
        if(t[i] == ' '){
            s.push_back("");
        }else{
            s[s.size() - 1].push_back(t[i]);
        }
    }
}

int main(){
    CFS;
    int n, m;
    cin >> n >> m;
    vector<vector<string>> s(n);
    string t;
    getline(cin, t);

    rep(i, n){
        getline(cin, t);
        parse(s[i], t);
    }

    string mi = "", ma = "";

    rep(i, m){
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        int q = 0;
        int x = 0, y = 0;
        rep(j, n){
            mp1[s[j][0]] = 0;
            auto itr1 = mp1.find(s[j][0]);
            mp2[s[j][0]] = 0;
            auto itr2 = mp2.find(s[j][0]);
            if(s[j].size() == 3){
                if(s[j][2] == "?"){
                    itr1->second = 0;
                    itr2->second = 1;
                }else{
                    itr1->second = s[j][2][i] - '0';
                    itr2->second = s[j][2][i] - '0';
                }
            }else{
                int a, b;
                if(s[j][2] == "?"){
                    a = 0;
                }else{
                    a = mp1[s[j][2]];
                }
                if(s[j][4] == "?"){
                    b = 0;
                }else{
                    b = mp1[s[j][4]];
                }
                if(s[j][3] == "AND"){
                    itr1->second = a & b;
                }else if(s[j][3] == "OR"){
                    itr1->second = a | b;
                }else{
                    itr1->second = a ^ b;
                }
                if(s[j][2] == "?"){
                    a = 1;
                }else{
                    a = mp2[s[j][2]];
                }
                if(s[j][4] == "?"){
                    b = 1;
                }else{
                    b = mp2[s[j][4]];
                }
                if(s[j][3] == "AND"){
                    itr2->second = a & b;
                }else if(s[j][3] == "OR"){
                    itr2->second = a | b;
                }else{
                    itr2->second = a ^ b;
                }
            }
        }
        for(auto &p:mp1){
            x += p.second;
        }
        for(auto &p:mp2){
            y += p.second;
        }
        if(x<y){
            mi.push_back('0');
            ma.push_back('1');
        }else if(x>y){
            mi.push_back('1');
            ma.push_back('0');
        }else{
            mi.push_back('0');
            ma.push_back('0');
        }
    }
    cout << mi << endl << ma << endl;
    return 0;
}