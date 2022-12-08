#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                cin>>a[i][j];
            }
        }
        vector<vector<char>> b(n, vector<char>(m));
        vector<vector<char>> c = b;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if((i+j)&1) b[i][j]='R',c[i][j]='W';
                else b[i][j]='W',c[i][j]='R';
            }
        }
        int ok1=1,ok2=1;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(a[i][j]!='.' && a[i][j]!=b[i][j]) ok1=0;
                if(a[i][j]!='.' && a[i][j]!=c[i][j]) ok2=0;
            }
        }
        if(ok1) {
            cout<<"YES"<<endl;
            for(int i=0;i<n;++i) {
                for(int j=0;j<m;++j) {
                    cout<<b[i][j];
                }
                cout<<endl;
            }
        } else if(ok2) {
            cout<<"YES"<<endl;
            for(int i=0;i<n;++i) {
                for(int j=0;j<m;++j) {
                    cout<<c[i][j];
                }
                cout<<endl;
            }
        } else {
            cout<<"NO"<<endl;
        }
    }
}