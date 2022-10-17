#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m = 4;
    vector<int> sz(m);
    for(int i=0;i<m;++i) cin>>sz[i];
    vector<vector<int>> a(m);
    for(int i=0;i<m;++i) {
        a[i].resize(sz[i]);
        for(int j=0;j<sz[i];++j) {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<m;++i) {
        multiset<int> s;
        for(int j:a[i-1]) if(j!=-1) s.insert(j);
        vector<vector<int>> pos(sz[i]);
        int k;
        cin>>k;
        while(k--) {
            int x,y;
            cin>>x>>y;
            --x, --y;
            pos[y].push_back(x);
        }
        for(int j=0;j<sz[i];++j) {
            for(int p:pos[j]) if(a[i-1][p]!=-1) s.erase(s.find(a[i-1][p]));
            if(!s.empty()) {
                a[i][j]+=*s.begin();
            } else {
                a[i][j]=-1;
            }
            for(int p:pos[j]) if(a[i-1][p]!=-1) s.insert(a[i-1][p]);
        }
        if(i==m-1) {
            int ans=-1;
            for(int j:a[i]) {
                if(j!=-1) {
                    if(ans==-1) ans=j;
                    else ans=min(ans,j);
                }
            }
            cout<<ans<<endl;
        }
    }
}