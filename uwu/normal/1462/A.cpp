#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        deque<int> q;
        for (int i=1,a;i<=n;++i) cin >> a, q.push_back(a);
        for (int i=1;i<=n;++i){
            if (i%2==1) cout << q.front() << " ", q.pop_front();
            else cout << q.back() << " ", q.pop_back();
        }
        cout << '\n';
    }
}