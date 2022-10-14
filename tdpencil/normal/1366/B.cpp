#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    cin >> test_case;

    for(int tt = 0; tt < test_case; tt++) {
        int n, m, x;
        cin >> n >> x >> m;

        int leftBound = x, rightBound = x;

        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            if(b > rightBound && a <= rightBound) rightBound = b;
            if(a < leftBound &&  b >= leftBound) leftBound = a;
        }


        cout << rightBound - leftBound + 1 << "\n";
    }
}