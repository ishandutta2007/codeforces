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
        int N, K;
        cin >> N >> K;

        for (int i = 0; i < N; i++)
            cin >> a[i];
        int ans=0;
        for (int i = 0; i < K; i++)
            if(a[i]>K)
                ans++;
        cout << ans << "\n";


    }
}