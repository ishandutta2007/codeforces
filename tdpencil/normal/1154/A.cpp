#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<int> V = {A, B, C, D};
    sort(V.begin(), V.end());
    A = V[0];
    B = V[1];
    C = V[2];
    D = V[3];
    cout << D - A << " " << D - B << " " << D - C << "\n";
}