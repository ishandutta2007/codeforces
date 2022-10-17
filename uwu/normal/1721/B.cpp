#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        int bx, by, d; cin >> bx >> by >> d;
        bool up = 1, down = 1, lef = 1, rig = 1;
        if (bx - d <= 1) up = 0;
        if (bx + d >= N) down = 0;
        if (by - d <= 1) lef = 0;
        if (by + d >= M) rig = 0;
        if ((up && rig) || (lef && down)){
            cout << N + M - 2 << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
}