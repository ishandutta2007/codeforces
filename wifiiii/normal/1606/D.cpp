#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i].back() > a[j].back();});
        vector<int> cut;
        vector<vector<int>> mx0(n, vector<int>(m)), mn0(n, vector<int>(m)),
                            mx1(n, vector<int>(m)), mn1(n, vector<int>(m));
        for(int j = 0; j < m; ++j) {
            mn0[0][j] = mx0[0][j] = a[ord[0]][j];
            mn1[n-1][j] = mx1[n-1][j] = a[ord[n-1]][j];
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                mn0[i][j] = min(mn0[i-1][j], a[ord[i]][j]);
                mx0[i][j] = max(mx0[i-1][j], a[ord[i]][j]);
            }
        }
        for(int i = n - 2; i >= 0; --i) {
            for(int j = 0; j < m; ++j) {
                mn1[i][j] = min(mn1[i+1][j], a[ord[i]][j]);
                mx1[i][j] = max(mx1[i+1][j], a[ord[i]][j]);
            }
        }
        int no = 1;
        for(int i = 0; i + 1 < n; ++i) {
            vector<int> pmx(m), pmn(m), smx(m), smn(m);
            pmx[0] = mx0[i][0], pmn[0] = mn1[i+1][0];
            smx[m-1] = mx1[i+1][m-1], smn[m-1] = mn0[i][m-1];
            for(int j = 1; j < m; ++j) {
                pmx[j] = max(pmx[j-1], mx0[i][j]);
                pmn[j] = min(pmn[j-1], mn1[i+1][j]);
            }
            for(int j = m - 2; j >= 0; --j) {
                smx[j] = max(smx[j+1], mx1[i+1][j]);
                smn[j] = min(smn[j+1], mn0[i][j]);
            }
            int pos = -1;
            for(int j = 0; j + 1 < m; ++j) {
                if(pmx[j] < pmn[j] && smx[j+1] < smn[j+1]) {
                    pos = j + 1;
                    break;
                }
            }
            if(pos != -1) {
                cout << "YES\n";
                string color(n, 'R');
                for(int j = 0; j <= i; ++j) color[ord[j]] = 'B';
                cout << color << " " << pos << '\n';
                assert(1 <= pos && pos < m);
                no = 0;
                break;
            }
        }
        if(no) cout << "NO\n";
    }
}