#include<bits/stdc++.h>
using namespace std;

int t;
int n,m;
int p[107], a[107];
bool vis[107];
int main(){
    cin>>t;
    while (t--){
        cin >> n >> m;
        for (int i = 1; i <= n;++i){
            cin >> a[i];
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= m;++i){
            cin >> p[i];
            vis[p[i]] = 1;
        }
        int i = 1,l = 1;
        while (i<=n){
            while (i<n&&vis[i])
                i++;
            sort(a + l, a + i + 1);
            i++, l = i;
        }
        for (int i = 1; i < n;++i){
            if (a[i]>a[i+1]){
                cout << "NO" << endl;
                goto cont;
            }
        }
        cout<<"YES"<<endl;
    cont:;
    }
}