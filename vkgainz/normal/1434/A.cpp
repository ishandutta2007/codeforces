#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mx[100001];
struct cmp {
    bool operator() (const pair<int,int> &x, const pair<int,int> &y) const {
        return x<y;
    }
};
set<pair<int,int>, cmp> s;
multiset<int> in;
int main() {
    int a[6];
    for(int i=0;i<6;i++) cin >> a[i];
    int n; cin >> n;
    int b[n];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a,a+6);
    sort(b,b+n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<6;j++) {
            s.insert({b[i]-a[j],i});
        }
    }
    auto it = s.begin();
    int ans = 2000000000;
    for(int i=0;i<n;i++) mx[i] = -1000000000, in.insert(mx[i]);
    while(it!=s.end()) {
        int x = it->first;
        int idx = it->second;
        in.erase(in.lower_bound(mx[idx]));
        mx[idx] = x;
        in.insert(mx[idx]);
        auto temp = in.begin();
        if((*temp)<0) {
            s.erase(it++);
            continue;
        }
        else {
            ans = min(ans,x-(*temp));
            s.erase(it++);
        }
    }
    cout << ans << endl;
}