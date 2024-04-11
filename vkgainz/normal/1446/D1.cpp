#include <bits/stdc++.h>
using namespace std;

int solve(int d, int v, vector<int> &a) {
    vector<int> p(a.size()+1);
    p[0] = 0;
    vector<int> x[4*a.size()+1];
    x[p[0]+a.size()+3].push_back(0);
    for(int i=0;i<a.size();i++) {
        p[i+1] = p[i];
        if(a[i]==v) --p[i+1];
        if(a[i]==d) ++p[i+1];
        x[p[i+1]+a.size()+3].push_back(i+1);
    }
    int ret = 0;
    for(int i=0;i<4*a.size();i++) {
        if(x[i].size()) {
            int r = x[i][x[i].size()-1];
            int l = x[i][0];
            ret = max(ret, r-l);
        }
    }
    //cout << d << " " << v << " " << ret << "\n";
    return ret;
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> f(200001);
    for(int i=0;i<n;i++) f[a[i]]++;
    int num = 0;
    int val = 0;
    for(int i=1;i<=n;i++) {
        if(f[i]>f[val]) {
            num = 1;
            val = i;
        }
        else if(f[i]==f[val]) {
            ++num;
        }
    }
    if(num>=2) {
        cout << n << endl;
        cout << "\n";
        return 0;
    }
    //cout << "bayus" << endl;
    int ans = 0;
    for(int i=1;i<=100;i++) {
        if(i!=val) ans = max(ans, solve(i, val, a));
    }
    cout << ans << "\n";
}