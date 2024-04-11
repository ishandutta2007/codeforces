#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;


int main() {
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        int a[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                cin >> a[i][j];
        }
        vector<pair<int, int>> x, y;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((i+j)%2) x.push_back({i,j});
                else y.push_back({i, j});
            }
        }
        int b[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) b[i][j] = a[i][j];
        for(auto &it : x) {
            if(b[it.f][it.s]%2) ++b[it.f][it.s];
        }
        for(auto &it : y) {
            if(b[it.f][it.s]%2==0) ++b[it.f][it.s];
        }
        for(int i=0;i<n;i++)  {
            for(int j=0;j<m;j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
}