#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> a(n,vector<char>(n));
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin>>a[i][j];
        // case 1. a[i][j] = a[j][i]
        int ok1=0;
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                if(a[i][j] == a[j][i]) {
                    ok1=1;
                    cout<<"YES"<<endl;
                    for(int k=0;k<=m;++k) {
                        if(k&1) cout<<i+1<<" ";
                        else cout<<j+1<<" ";
                    }
                    cout<<endl;
                    break;
                }
            }
            if(ok1) break;
        }
        if(ok1) continue;
        // case2. n = 2
        if(n == 2) {
            if(m % 2 == 1) {
                cout<<"YES"<<endl;
                for(int k=0;k<=m;++k) {
                    if(k&1) cout<<1<<" ";
                    else cout<<2<<" ";
                }
                cout<<endl;
            } else {
                cout<<"NO"<<endl;
            }
            continue;
        }
        // case3. n > 2 and m % 2 = 1, ababa
        assert(n > 2);
        if(m % 2 == 1) {
            cout<<"YES"<<endl;
            for(int k=0;k<=m;++k) {
                if(k&1) cout<<1<<" ";
                else cout<<2<<" ";
            }
            cout<<endl;
            continue;
        }
        // case4. n > 2 and m % 4 = 2, aabbaabbaa...
        if(m % 4 == 2) {
            vector<int> ord{0,1,2};
            int ok2=0;
            do {
                int x=ord[0],y=ord[1],z=ord[2];
                // x--->y--->z--->y--->x--->y--->...
                //   a    a    b    b    a
                if(a[x][y] == a[y][z]) {
                    ok2 = 1;
                    cout << "YES" << endl;
                    assert(a[z][y] != a[y][z] && a[y][x] != a[x][y]);
                    for(int i=0;i<m/4;++i) {
                        cout<<x+1<<" "<<y+1<<" "<<z+1<<" "<<y+1<<" ";
                    }
                    cout<<x+1<<" "<<y+1<<" "<<z+1<<endl;
                    break;
                }
            }while(next_permutation(ord.begin(), ord.end()));
            assert(ok2);
            continue;
        }
        // case 5. n > 2 and m % 4 = 0, abba|abba|abba|...
        assert(m % 4 == 0);
        vector<int> ord{0,1,2};
        int ok3=0;
        do {
            int x=ord[0],y=ord[1],z=ord[2];
            // x--->y--->x--->z--->x--->y--->...
            //   a    b    b    a    a
            if(a[x][y] == a[z][x]) {
                ok3 = 1;
                cout << "YES" << endl;
                for(int i=0;i<m/4;++i) {
                    cout<<x+1<<" "<<y+1<<" "<<x+1<<" "<<z+1<<" ";
                }
                cout<<x+1<<endl;
                break;
            }
        }while(next_permutation(ord.begin(), ord.end()));
        assert(ok3);
    }
}