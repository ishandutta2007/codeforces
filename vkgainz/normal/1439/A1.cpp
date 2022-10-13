#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int grid[101][101];
void upd(int x,int y) {
    ans.push_back(x);
    ans.push_back(y);
    grid[x][y] = 1-grid[x][y];
}
void ch(int i, int j) {
    int a = grid[i][j];
    int b = grid[i][j+1];
    int c = grid[i+1][j];
    int d = grid[i+1][j+1];
    if(a+b+c+d==0) return;
    if(a+b+c+d==1) {
        int num = 0;
        for(int x=i;x<i+2;x++) {
            for(int y=j;y<j+2;y++) {
                if(grid[x][y]==1) {
                    upd(x,y);
                }
                else {
                    ++num;
                    if(num<3) upd(x,y);
                }
            }
        }
        ch(i, j);
    }
    if(a+b+c+d==2) {
        int num = 0;
        for(int x=i;x<i+2;x++) {
            for(int y=j;y<j+2;y++) {
                if(grid[x][y]==0) {
                    upd(x, y);
                }
                else {
                    ++num;
                    if(num<2) upd(x,y);
                }
            }
        }
        ch(i, j);
    }
    if(a+b+c+d==3) {
        for(int x=i;x<i+2;x++) {
            for(int y=j;y<j+2;y++) {
                if(grid[x][y]==1) {
                    upd(x,y);
                }
            }
        }
        return;
    }
    if(a+b+c+d==4) {
        for(int x=i;x<i+2;x++) {
            for(int y=j;y<j+2;y++) {
                if(x==i+1 && y==j+1) continue;
                else {
                    upd(x,y);
                }
            }
        }
        ch(i, j);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        for(int i=0;i<n;i++) {
            string s; cin >> s;
            for(int j=0;j<m;j++)
                grid[i][j] = s[j]-'0';
        }
        ans.clear();
        for(int i=0;i+1<n;i+=2) {
            for(int j=0;j+1<m;j+=2) {
                ch(i, j);
            }
        }
        if(m%2) {
            for(int i=0;i+1<n;i+=2) {
                ch(i, m-2);
            }
        }
        if(n%2) {
            for(int j=0;j+1<m;j+=2) {
                ch(n-2, j);
            }
        }
        ch(n-2, m-2);
        cout << ans.size()/6 << "\n";
        for(auto &it : ans) cout << it+1 << " ";
        cout << "\n";
    }
}