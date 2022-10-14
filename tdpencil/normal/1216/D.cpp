#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> A(N);
    for(auto &a: A)
    	cin >> a;


    vector<int> distances;
    int mx = *max_element(A.begin(), A.end());
    for(int i = 0; i < N; i++) {
    	distances.push_back(mx - A[i]);
    }

    // greatest common divisor of all of them

    int x = 0;
    for(auto &e: distances)
    	x = __gcd(x, e);


    int64_t f1 = 0;

    for(int i = 0; i < N; i++) {
    	f1 += (mx - A[i]) / x;
    }

    cout << f1 << " " << x << "\n";

}