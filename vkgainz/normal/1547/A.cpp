#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        pair<int, int> A, B, F;
        cin >> A.first >> A.second;
        cin >> B.first >> B.second;
        cin >> F.first >> F.second;
        if(A.first == B.first || (A.second == B.second)) {
            if(A.first == B.first && A.first == F.first && F.second >= min(A.second, B.second) && F.second <= max(A.second, B.second)) {
                cout << abs(A.second - B.second) + 2 << "\n";
            }
            else if(A.second == B.second && A.second == F.second && F.first >= min(A.first, B.first) && F.first <= max(A.first, B.first)) {
                cout << abs(A.first - B.first) + 2 << "\n";
            }
            else {
                cout << abs(A.first - B.first) + abs(A.second - B.second) << "\n";
            }
        }
        else {
            cout << abs(A.first - B.first) + abs(A.second - B.second) << "\n";
        }
    }
}