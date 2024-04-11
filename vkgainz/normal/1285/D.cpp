#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int solve(vector <int> &c, int bit){
    if(bit < 0) return 0;
    vector <int> l, r;
    for(auto &i : c){
        if(((i >> bit) & 1) == 0) l.push_back(i);
        else r.push_back(i);
    }
    if(l.size() == 0) return solve(r, bit - 1);
    if(r.size() == 0) return solve(l, bit - 1);
    return min(solve(l, bit - 1), solve(r, bit - 1)) + (1 << bit);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    cout << solve(a, 30) << endl;
}