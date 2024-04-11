#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template<typename T> void sort_array(vector<T> &a) {
    multiset<int> s;
    for(T i : a) s.insert(i);
    a.clear();
    for(T i : s) a.push_back(i);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i < N; i++) cin >> A[i];
    sort_array(A);
    int ans = 0;
    for(int i=0; i < N; i++) ans += A[N-1] - A[i];

    cout << ans << "\n";
}