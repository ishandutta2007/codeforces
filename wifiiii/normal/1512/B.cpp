#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<char>> a(n,vector<char>(n));
        vector<pair<int,int>> b;
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                cin>>a[i][j];
                if(a[i][j]=='*') {
                    b.push_back({i,j});
                }
            }
        }
        assert(b.size()==2);
        int x1=b[0].first,y1=b[0].second;
        int x2=b[1].first,y2=b[1].second;
        if(x1!=x2 && y1!=y2) {
            a[x1][y2]=a[x2][y1]='*';
        } else if(x1!=x2) {
            int y=y1?0:1;
            a[x1][y]=a[x2][y]='*';
        } else {
            int x=x1?0:1;
            a[x][y1]=a[x][y2]='*';
        }
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) cout<<a[i][j];
            cout<<endl;
        }
    }
}