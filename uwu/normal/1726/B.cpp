#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        if (N > M){
            cout << "No" << '\n';
            continue;
        }
        if (N % 2 == 0 && M % 2 == 1){
            cout << "No" << '\n';
            continue;
        }
        cout << "Yes" << '\n';
        while (N > 2){
            cout << 1 << " " << 1 << " ";
            N -= 2;
            M -= 2;
        }
        if (N == 2){
            cout << M/2 << " " << M/2 << '\n';
        }
        else{
            cout << M << '\n';
        }
    }
}