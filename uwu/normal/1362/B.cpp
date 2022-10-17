#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        bool vis[1024]={0},temp[1024]={0};
        int arr[n+1];
        for (int i=1;i<=n;++i) cin >> arr[i],vis[arr[i]]=1;

        int end=false;
        for (int k=1;k<1024;++k){
            ms(temp,0);
            for (int i=1;i<=n;++i){
                temp[arr[i]^k]=1;
            }
            bool flag=true;
            for (int i=0;i<1024;++i){
                flag&=(vis[i]==temp[i]);
            }
            if (flag){ cout << k << '\n'; end=true; break; }
        }
        if (!end) cout << -1 << '\n';
    }
}