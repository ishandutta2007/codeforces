#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int solve(vector<int> a, vector<int> b) {
    if(a.empty() || b.empty()) return 0;
    vector<int> aa = a;
    for(int i = 0; i < aa.size(); ++i) aa[i] -= i;
    map<int,int> mp;
    for(int i : b) mp[i]++;
    vector<int> dpa(a.size()+1);
    for(int i = a.size()-1; i >= 0; --i) {
        if(mp.count(a[i])) dpa[i] = 1;
        dpa[i] += dpa[i+1];
    }
    int ans = dpa[0];
    for(int i = 0; i < b.size(); ++i) {
        // push a[0] to b[i]
        if(a[0] >= b[i]) continue;
        int continuous_boxes = upper_bound(aa.begin(), aa.end(), b[i]) - aa.begin();
        int suffix = dpa[continuous_boxes];
        int prefix = lower_bound(b.begin(), b.end(), b[i] + continuous_boxes) - lower_bound(b.begin(), b.end(), b[i]);
        ans = max(ans, prefix + suffix);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<int> a1,a2,b1,b2;
        for(int i=0;i<n;++i) {
            int x;
            cin>>x;
            if(x<0) a1.push_back(-x);
            else a2.push_back(x);
        }
        for(int i=0;i<m;++i) {
            int x;
            cin>>x;
            if(x<0) b1.push_back(-x);
            else b2.push_back(x);
        }
        sort(a1.begin(), a1.end());
        sort(b1.begin(), b1.end());
        sort(a2.begin(), a2.end());
        sort(b2.begin(), b2.end());
        int ans=0;
        cout<<solve(a1,b1)+solve(a2,b2)<<endl;
    }
}