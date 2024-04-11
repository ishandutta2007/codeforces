#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template<typename T> void sort_array(vector<T> &a) {
    set<int> s;
    for(T i : a) s.insert(i);
    a.clear();
    for(T i : s) a.push_back(i);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);


    vector<int> A(3);
    cin >> A[0] >> A[1] >> A[2];
    sort_array(A);
    cout << A[2] - A[0];
}