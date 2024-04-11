#include <bits/stdc++.h>


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;
    if( N % 10 <= 5 ) {
        N -= N % 10;
    } else {
        N += 10 - N % 10;
    }

    cout << N << '\n';
}