#include<iostream>
#include<string>
#include<vector>

using namespace std;
#define rep(i, n) for(int i=0;i<n;++i)
#define repl(i, l, n) for(int i=l;i<n;++i)


int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<char, int>> v;
    char pre = s[0];
    int count = 1;
    repl(i, 1, n){
        if(s[i] == pre){
            count++;
        }else{
            v.push_back({pre, count});
            count = 1;
        }
        pre = s[i];
    }
    v.push_back({pre, count});
    int m = v.size();
    if(m % 2 == 0){
        cout << 0 << endl;
        return 0;
    }
    rep(i, m / 2){
        if(v[i].first != v[m - i - 1].first){
            cout << 0 << endl;
            return 0;
        }
        if(v[i].second + v[m - i - 1].second < 3){
            cout << 0 << endl;
            return 0;
        }
    }
    if(v[m/2].second<2) cout << 0 << endl;
    else cout << v[m/2].second+1 << endl;
    return 0;
}