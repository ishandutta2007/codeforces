#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

typedef long double ld;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n), vis(n);
    for(int i=0;i<n;++i) cin>>x[i]>>y[i];
    auto dis = [&](int i, int j) {
        return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    };
    vector<int> ans;
    vis[0]=1;
    ans.push_back(0);
    for(int i=0;i<n-1;++i) {
        int p=ans.back();
        ll mx=-1,idx=-1;
        for(int j=0;j<n;++j) {
            if(vis[j]) continue;
            ll d=dis(p,j);
            if(d>mx) {
                mx=d;
                idx=j;
            }
        }
        assert(idx!=-1);
        ans.push_back(idx);
        vis[idx]=1;
    }
    for(int i:ans) cout<<i+1<<" ";cout<<endl;
}