#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 2e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        vector<int> pos[n+1];
        for(int i=0;i<n;i++)
            pos[a[i]].push_back(i);
        int ret = n+1;
        for(int i=1;i<=n;i++) {
            if(pos[i].size()==0) continue;
            int cmp = pos[i].size()+1;
            if(pos[i][0]==0) --cmp;
            if(pos[i][pos[i].size()-1]==n-1) --cmp;
            for(int j=1;j<pos[i].size();j++)
                if(pos[i][j]-pos[i][j-1]==1) --cmp;
            ret =min(ret, cmp);
        }
        cout << ret << "\n";
    }
}