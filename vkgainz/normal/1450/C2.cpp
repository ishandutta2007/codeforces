#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 1e5+5;
char g[305][305];
int n;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int k = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> g[i][j];
                if(g[i][j]!='.') ++k;
            }
        }
        bool found = false;
        for(int x=0;x<3;x++) {
            for(int y=0;y<3;y++) {
                if(x==y || found) continue;
                int numOp = 0;
                char temp[n][n];
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        temp[i][j] = g[i][j];
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        int par = (i+j)%3;
                        if(par==x) {
                            if(temp[i][j]=='O')
                                temp[i][j] = 'X', ++numOp;
                        }
                        else if(par==y) {
                            if(temp[i][j]=='X')
                                temp[i][j] = 'O', ++numOp;
                        }
                        else continue;
                    }
                }
                if(numOp<=k/3) {
                    found = 1;
                    for(int i=0;i<n;i++) {
                        for(int j=0;j<n;j++) {
                            cout << temp[i][j];
                        }
                        cout << "\n";
                    }
                }
            }
        }
    }
}