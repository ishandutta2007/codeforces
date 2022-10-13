#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

int main() {
    int n; cin >> n;
    vector<pair<bool,int>> v;
    for(int i=0;i<2*n;i++) {
        char t; cin >> t;
        if(t=='+') v.push_back({1,0});
        else {
            int x; cin >> x;
            v.push_back({0,x});
        }
    }
    set<int> s;
    bool work = true;
    vector<int> ord;
    for(int i=2*n-1;i>=0 && work;i--) {
        if(!v[i].f) s.insert(v[i].s);
        else {
            if(s.empty()) work = false;
            else {
                ord.push_back(*s.begin());
                s.erase(s.begin());
            }
        }
    }
    if(!work) {
        cout << "NO" << endl;
        return 0;
    }
    set<int> in;
    reverse(ord.begin(),ord.end());
    int idx = 0;
    for(int i=0;i<2*n && work;i++) {
        if(v[i].f) {
            in.insert(ord[idx++]);
        }
        else {
            if(in.empty()) work = false;
            else {
                if(*in.begin()!=v[i].s)  {
                    work = false;
                }
                else in.erase(in.begin());
            }
        }
    }
    if(work) {
        cout << "YES" << endl;
        for(auto &it : ord) cout << it << " ";
    }
    else cout << "NO" << endl;
}