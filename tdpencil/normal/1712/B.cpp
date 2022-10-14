#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;
int T;
const int mxN=2e5;
int a[mxN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T; 
    while(T--) {
        int N;
        cin >> N;
        if (N % 2 == 0) {
            for (int i = 1; i <= N; i+=2) {
                cout << i + 1 << " " << i << " ";
            }
            cout << "\n";
        } else {
            cout << 1 << " ";
            for (int i = 2; i <= N; i+=2) {
                cout << i + 1 << " " << i << " ";
            }
            cout << "\n";
        }

    }
}