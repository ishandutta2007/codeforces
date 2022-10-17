#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
int prime[maxn],np[maxn],tot=0;
void init(int n) {
   np[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot] = i;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>n) break;
           np[i*prime[j]] = 1;
           if(i%prime[j]==0) break;
       }
   }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(maxn - 1);
    int t;
    cin >> t;
    while(t--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        ll ans = 0;
        auto solve = [&](vector<int> b) -> ll {
            ll ret = 0;
            vector<int> pos {-1};
            for(int i = 0; i < b.size(); ++i) {
                if(b[i] == 1) {
                    ret += i - pos.back() - 1;
                    pos.push_back(i);
                } else {
                    if(pos.size()>1) ret += pos[pos.size()-1] - pos[pos.size()-2];
                }
            }
            return ret;
        };
        for(int i = 0; i < e; ++i) {
            vector<int> b;
            for(int j = i; j < n; j += e) {
                int x = a[j];
                if(x == 1) {
                    b.push_back(0);
                } else if(!np[x]) {
                    b.push_back(1);
                } else {
                    ans += solve(b);
                    b.clear();
                }
            }
            ans += solve(b);
            b.clear();
        }
        cout << ans << '\n';
    }
}