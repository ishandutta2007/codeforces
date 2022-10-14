#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> s;
    int mex = 0;

    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    for(auto &e: s) {
        if(e == mex)
            mex++;
    }

    if(mex == N) {
        cout << N + M << "\n";
        return;
    }


    while(M--) {
        int mx = *(s.rbegin());
        if( s.count((mex+mx+1) / 2 )) break;
        s.insert((mex+mx+1) / 2);
    }


    cout << s.size() << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T = 1;
    cin >> T; 
    while(T--)
        solve();
}