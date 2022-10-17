#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
map<int,int> m;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        m.clear();
        int n; cin >> n;
        int t1=-1;
        int t2=0;
        for (int i=0,a;i<n;++i){
            cin >> a;
            m[a]++;
            if (m[a]==1) t1++;
            t2=max(t2,m[a]);
        }
        int ans=max(min(t1,t2),min(t1+1,t2-1));
        cout << ans << '\n';
    }
}