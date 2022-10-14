#include <bits/stdc++.h>

#define rep(i,j,n) for(int i = j; i < n; i++)
#define vi vector<int>
#define all(x) begin(x), end(x);
#define double long double
int main() {
    using namespace std;

    int T = 1;
    // cin >> T;
    for(int test_case = 0; test_case < T; test_case++) {
        // the rule is a[1] = 1
        // a[2 * i] = a[i] + 1 
        // a[2 * i  + 1] = 1
        //

        int64_t id, n;
        cin >> n >> id;
        int O = 0; 
        while(id > 1) {
            if(id % 2 == 0)
                O += 1, id /= 2;
            else
                break; 
        }
        cout << O + 1 << "\n";
    }

}