#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    set<pair<int, int>> S;

    int N; cin >> N;
    vector<int> A(N);

    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++)
        S.insert({A[i], i});

    int res = 0;

    sort(A.rbegin(), A.rend());

    int cur = 0;

    for(int i = 0; i < N; i++) {
        res += A[i] * cur + 1;
        cur++;
        
    }


    cout << res << "\n";

    for(int i = 0; i < N; i++) {
        pair<int, int> res = *S.lower_bound(make_pair(A[i], 0));
        cout << res.second + 1 << " ";
        S.erase(res);
    }
    cout << "\n";
}