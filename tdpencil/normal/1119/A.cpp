#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int N;cin >> N;
    vector<int64_t> A(N);
    for(int i=0; i < N; i++)
        cin >> A[i];
    int ans = 0;
    for(int i=0; i < N; i++) {
        if(A[i] != A[N-1]) {
            ans = max(N-1 - i, ans);
        }
    }
    for(int i = 0; i < N; i++) {
        if(A[i] != A[0]) {
            ans = max(ans, i);
        }
    }
    cout << ans << '\n';
    return 0;
    cout << "EROR CORREREd";
}