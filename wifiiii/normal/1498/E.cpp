#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int in, id;
    bool operator < (const node & n) const {
        return in < n.in;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<node> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i].in, a[i].id = i;
    sort(a.begin(), a.end());
    vector<pair<node, node>> v;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            v.push_back({a[i], a[j]});
        }
    }
    sort(v.begin(), v.end(), [&](auto i, auto j) {return abs(i.first.in - i.second.in) > abs(j.first.in - j.second.in);});
    for(auto p : v) {
        cout << "? " << p.first.id + 1 << " " << p.second.id + 1 << endl;
        string ret;
        cin >> ret;
        if(ret[0] == 'Y') {
            return cout << "! " << p.first.id + 1 << " " << p.second.id + 1 << endl, 0;
        }
    }
    cout << "! 0 0" << endl;
}