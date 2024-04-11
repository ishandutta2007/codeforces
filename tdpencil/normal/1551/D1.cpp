#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    int tt; cin >> tt;
    
    while(tt--) {
        int n, m, k;
        cin >> n >> m >> k;

        if(n%2==0&&m%2==0) {
            if(k%2)
                cout << "NO\n";
            else
                cout << "YES\n";
        } else if(n%2 == 0) {
            // odd rows
            // ***
            // ***
            // n = 2, m = 3
            if(k <= (m - 1) * n / 2 && k % 2 == 0 && k >= 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else if(m%2 == 0) {
            int took = m / 2;
            // odd cols
            // **
            // **
            // **
            // 3 2
            k -= took; 
            if(k <= (n - 1) * m / 2 && k % 2 == 0 && k >= 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }    
}