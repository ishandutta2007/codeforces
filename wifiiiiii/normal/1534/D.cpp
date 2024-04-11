#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int g[2005][2005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    cout << "? " << 1 << endl;
    vector<int> a(n + 1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<int> x,y;
    for(int i=1;i<=n;++i) {
        if(a[i]==1) g[1][i]=g[i][1]=1;
        if(a[i]&1) x.push_back(i);
        else y.push_back(i);
    }
    if(x.size()+1 <= (n+1)/2) {
        for(int u:x) {
            cout<<"? "<<u<<endl;
            for(int i=1;i<=n;++i) cin>>a[i];
            for(int i=1;i<=n;++i) {
                if(a[i]==1) g[u][i]=g[i][u]=1;
            }
        }
    } else {
        assert(y.size() <= (n+1)/2);
        for(int u:y) {
            if(u==1) continue;
            cout<<"? "<<u<<endl;
            for(int i=1;i<=n;++i) cin>>a[i];
            for(int i=1;i<=n;++i) {
                if(a[i]==1) g[u][i]=g[i][u]=1;
            }
        }
    }
    cout<<"!"<<endl;
    for(int i=1;i<=n;++i) {
        for(int j=i+1;j<=n;++j) {
            if(g[i][j] || g[j][i]) cout<<i<<" "<<j<<endl;
        }
    }
}