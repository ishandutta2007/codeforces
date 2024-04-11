#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        deque<int> q;
        for (int i=1;i<=n;++i){
            int x; cin >> x;
            q.push_back(x);
        }
        sort(q.begin(),q.end());
        int most=q[1]-q[0], best=q[0];
        for (int i=0;i<n-1;++i){
            if (q[i+1]-q[i]<most) most=q[i+1]-q[i], best=q[i];
        }
        while (true){
            int x=q.front(); q.pop_front(); q.push_back(x);
            if (x==best) break;
        }
        if (n==2) sort(q.begin(),q.end());
        for (int i=0;i<n;++i) cout << q[i] << " ";
        cout << '\n';
    }
}