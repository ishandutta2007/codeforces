#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
const int N = 1000001;
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        int row[n][m], col[m][n];
        int r[250000], c[250000];
        for(int i=0;i<n;i++) 
            for(int j=0;j<m;j++) cin >> row[i][j];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) cin >> col[i][j];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                c[row[i][j]-1] = j;
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                r[col[i][j]-1] = j;
            }
        }
        int ans[n][m];
        for(int i=0;i<n*m;i++) {
            ans[r[i]][c[i]] = i;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                cout << ans[i][j]+1 << " ";
            cout << endl;
        }

    }
}